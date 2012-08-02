/****************************************************************************
**
** Copyright (C) 2012 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Commercial Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#include "chartintervalsaxisy_p.h"
#include "qintervalsaxis.h"
#include "qabstractaxis.h"
#include "chartpresenter_p.h"
#include <QGraphicsLayout>
#include <QFontMetrics>
#include <qmath.h>


static int label_padding = 5;

QTCOMMERCIALCHART_BEGIN_NAMESPACE

ChartIntervalAxisY::ChartIntervalAxisY(QAbstractAxis *axis,ChartPresenter *presenter) : ChartAxis(axis,presenter)
{
}

ChartIntervalAxisY::~ChartIntervalAxisY()
{
}

QVector<qreal> ChartIntervalAxisY::calculateLayout() const
{
    QIntervalsAxis *axis = qobject_cast<QIntervalsAxis *>(m_chartAxis);
    int tickCount = axis->intervalsLabels().count() + 1;
    QVector<qreal> points;

    if (tickCount < 2)
        return points;

    points.resize(tickCount);

    qreal scale = m_rect.height() / axis->max();
    for (int i = 0; i < tickCount; ++i)
        if (i < tickCount - 1) {
            int y = -axis->intervalMin(axis->intervalsLabels().at(i)) * scale + m_rect.bottom();
            points[i] = y;
        } else {
            int y = -axis->intervalMax(axis->intervalsLabels().at(i - 1))  * scale + m_rect.bottom();
            points[i] = y;
        }

    return points;
}

void ChartIntervalAxisY::updateGeometry()
{
    const QVector<qreal> &layout = ChartAxis::layout();
    m_minWidth = 0;
    m_minHeight = 0;

    if(layout.isEmpty()) return;

    QIntervalsAxis *intervalAxis = qobject_cast<QIntervalsAxis *>(m_chartAxis);

    QStringList ticksList = intervalAxis->intervalsLabels();

    QList<QGraphicsItem *> lines = m_grid->childItems();
    QList<QGraphicsItem *> labels = m_labels->childItems();
    QList<QGraphicsItem *> shades = m_shades->childItems();
    QList<QGraphicsItem *> axis = m_arrow->childItems();

    //    Q_ASSERT(labels.size() == ticksList.size());
    //    Q_ASSERT(layout.size() == ticksList.size());

    qreal height =  2*m_rect.bottom();

    QGraphicsLineItem *lineItem = static_cast<QGraphicsLineItem*>(axis.at(0));
    lineItem->setLine(m_rect.left() , m_rect.top(), m_rect.left(), m_rect.bottom());

    for (int i = 0; i < layout.size(); ++i) {
        QGraphicsLineItem *lineItem = static_cast<QGraphicsLineItem*>(lines.at(i));
        lineItem->setLine(m_rect.left() , layout[i], m_rect.right(), layout[i]);
        QGraphicsSimpleTextItem *labelItem = static_cast<QGraphicsSimpleTextItem*>(labels.at(i));

        if (i < ticksList.count()) {
            labelItem->setText(ticksList.at(i));
        }
        const QRectF& rect = labelItem->boundingRect();

        QPointF center = rect.center();
        labelItem->setTransformOriginPoint(center.x(), center.y());

        if (i < ticksList.count())
            labelItem->setPos(m_rect.left() - rect.width() - label_padding , layout[i] + (layout[i + 1] - layout[i]) / 2 - center.y());
        else
            labelItem->setPos(m_rect.left() - rect.width() - label_padding , layout[i]-center.y());

        if(labelItem->pos().y()+rect.height()>height) {
            labelItem->setVisible(false);
            lineItem->setVisible(false);
        }
        else {
            labelItem->setVisible(true);
            lineItem->setVisible(true);
            height=labelItem->pos().y();
        }

        m_minWidth=qMax(rect.width()+label_padding,m_minWidth);
        m_minHeight+=rect.height();

        if ((i+1)%2 && i>1) {
            QGraphicsRectItem *rectItem = static_cast<QGraphicsRectItem*>(shades.at(i/2-1));
            rectItem->setRect(m_rect.left(),layout[i],m_rect.width(),layout[i-1]-layout[i]);
        }
        lineItem = static_cast<QGraphicsLineItem*>(axis.at(i+1));
        lineItem->setLine(m_rect.left()-5,layout[i],m_rect.left(),layout[i]);
    }
}

void ChartIntervalAxisY::handleAxisUpdated()
{
    updateGeometry();
    ChartAxis::handleAxisUpdated();
}

QTCOMMERCIALCHART_END_NAMESPACE
