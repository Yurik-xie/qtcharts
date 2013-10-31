/****************************************************************************
**
** Copyright (C) 2013 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Enterprise Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Enterprise licenses may use this file in
** accordance with the Qt Enterprise License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#include "declarativebarseries.h"
#include "declarativeboxplotseries.h"
#include "qboxset.h"
#include "qvboxplotmodelmapper.h"

QTCOMMERCIALCHART_BEGIN_NAMESPACE

#ifdef QDOC_QT5
/*!
    \qmltype BoxSet
    \instantiates QBoxSet
    \inqmlmodule QtCommercial.Chart

    \include doc/src/declarativeboxset.qdocinc
*/
#else
/*!
    \qmlclass BoxSet QBoxSet

    \include ../doc/src/declarativeboxset.qdocinc
*/
#endif
/*!
    \qmlproperty string BoxSet::values
    The values on the box-and-whiskers set.
*/
/*!
    \qmlproperty string BoxSet::label
    Defines the label of the box-and-whiskers set.
*/
/*!
    \qmlproperty int BoxSet::count
    The count of values on the box-and-whiskers set
*/
/*!
    \qmlmethod void BoxSet::at(int index)
    Returns the value at \a index position.
*/
/*!
    \qmlmethod void BoxSet::append(qreal value)
    Appends new value \a value to the end of set.
*/
/*!
    \qmlmethod void BoxSet::clear()
    Sets all values on the set to 0.
*/
/*!
    \qmlmethod void BoxSet::setValue(int index, qreal value)
    Sets a new \a value on the \a index position.
*/
/*!
    \qmlsignal BoxSet::onClicked()
    This signal is emitted when the user clicks with a mouse on top of box-and-whiskers item.
*/
/*!
    \qmlsignal BoxSet::onHovered(bool status)
    The signal is emitted if mouse is hovered on top of box-and-whiskers item.
    Parameter \a status is true, if mouse entered on top of the item, and false if mouse left from top of the item.
*/
/*!
    \qmlsignal BoxSet::onPenChanged()
    This signal is emitted when the pen of the box-and-whiskers item has changed.
*/
/*!
    \qmlsignal BoxSet::onBrushChanged()
    This signal is emitted when the brush of the box-and-whiskers item has changed.
*/
/*!
    \qmlsignal BoxSet::onChangedValues()
    This signal is emitted when multiple values have been changed on the box-and-whiskers item.
*/
/*!
    \qmlsignal BoxSet::onChangedValue(int index)
    This signal is emitted values the value in the box-and-whiskers item has been modified.
    Parameter \a index indicates the position of the modified value.
*/
/*!
    \qmlsignal BoxSet::onCleared()
    This signal is emitted when all the values on the set are cleared to 0.
*/


#ifdef QDOC_QT5
/*!
    \qmltype BoxPlotSeries
    \instantiates QBoxPlotSeries
    \inqmlmodule QtCommercial.Chart

    \include doc/src/declarativeboxplotseries.qdocinc
*/
#else
/*!
    \qmlclass BoxPlotSeries QBoxPlotSeries

    \include ../doc/src/declarativeboxplotseries.qdocinc
*/
#endif

/*!
    \qmlmethod BoxPlotSeries::append(string label, VariantList values)
    Appends a new box-and-whiskers set with \a label and \a values to the series.
 */
/*!
    \qmlmethod BoxPlotSeries::append(BoxSet box)
    Appends the \a box to the series.
*/
/*!
    \qmlmethod BoxPlotSeries::insert(int index, string label, VariantList values)
    Inserts a new box-and-whiskers set with \a label and \a values at the \a index position.
*/
/*!
    \qmlmethod BoxPlotSeries::remove(QBoxSet boxset)
    Removes the \a boxset from the series.
*/
/*!
    \qmlmethod BoxPlotSeries::clear()
    Removes all boxsets from the series. Deletes removed sets.
*/
/*!
    \qmlsignal BoxPlotSeries::onClicked(BoxSet boxset);
    Signal is emitted when the user clicks the \a boxset on the chart.
*/
/*!
    \qmlsignal BoxPlotSeries::onHovered(bool status, BoxSet boxset);
    Signal is emitted when there is change in hover \a status over \a boxset.
*/
/*!
    \qmlsignal BoxPlotSeries::onCountChanged();
    Signal is emitted when there is change in count of box-and-whiskers items in the series.
*/
/*!
    \qmlsignal BoxPlotSeries::onBoxsetsAdded()
    Signal is emitted when new box-and-whiskers sets are added to the series.
 */
/*!
    \qmlsignal BoxPlotSeries::onBoxsetsRemoved()
    Signal is emitted when new box-and-whiskers sets are removed from the series.
 */
/*!
    \qmlproperty AbstractAxis BoxPlotSeries::axisX
    The x axis used for the series. If you leave both axisX and axisXTop undefined, a BarCategoriesAxis is created for
    the series.
    \sa axisXTop
*/
/*!
    \qmlproperty AbstractAxis BoxPlotSeries::axisY
    The y axis used for the series. If you leave both axisY and axisYRight undefined, a ValueAxis is created for
    the series.
    \sa axisYRight
*/
/*!
    \qmlproperty AbstractAxis BoxPlotSeries::axisXTop
    The x axis used for the series, drawn on top of the chart view. Note that you can only provide either axisX or
    axisXTop, but not both.
    \sa axisX
*/
/*!
    \qmlproperty AbstractAxis BoxPlotSeries::axisYRight
    The y axis used for the series, drawn to the right on the chart view. Note that you can only provide either axisY
    or axisYRight, but not both.
    \sa axisY
*/
/*!
    \qmlproperty bool BoxPlotSeries::boxOutlineVisible
    This property configures the visibility of the middle box outline.
*/
/*!
    \qmlproperty qreal BoxPlotSeries::boxWidth
    This property configures the width of the box-and-whiskers item. The value signifies the relative
    width of the box-and-whiskers item inside its own slot. The value can between 0.0 and 1.0. Negative values
    are clamped to 0.0 and values over 1.0 are clamped to 1.0.
*/
/*!
    \qmlproperty Pen BoxPlotSeries::pen
    This property configures the pen of the box-and-whiskers items.
*/
/*!
    \qmlproperty Brush BoxPlotSeries::brush
    This property configures the brush of the box-and-whiskers items.
*/
/*!
    \qmlsignal BoxPlotSeries::onBoxOutlineVisibilityChanged()
    Signal is emitted when the middle box outline visibility is changed.
 */
/*!
    \qmlsignal BoxPlotSeries::onBoxWidthChanged()
    Signal is emitted when the width of the box-and-whiskers item is changed.
 */
/*!
    \qmlsignal BoxPlotSeries::onPenChanged()
    Signal is emitted when the pen for box-and-whiskers items has changed.
*/
/*!
    \qmlsignal BoxPlotSeries::onBrushChanged()
    Signal is emitted when the brush for box-and-whiskers items has changed.
*/
/*!
    \qmlsignal BoxPlotSeries::onClicked(BoxSet boxset)
    Signal is emitted when the user clicks the \a boxset on the chart.
*/
/*!
    \qmlsignal BoxPlotSeries::onHovered(bool status, BoxSet boxset)
    Signal is emitted when there is change in hover \a status over \a boxset.
*/
/*!
    \qmlsignal BoxPlotSeries::onAxisXChanged(AbstractAxis axis)
    Signal is emitted when there is change in X axis.
*/
/*!
    \qmlsignal BoxPlotSeries::onAxisYChanged(AbstractAxis axis)
    Signal is emitted when there is change in Y axis.
*/
/*!
    \qmlsignal BoxPlotSeries::onAxisXTopChanged(AbstractAxis axis)
    Signal is emitted when there is change in top X axis.
*/
/*!
    \qmlsignal BoxPlotSeries::onAxisYRightChanged(AbstractAxis axis)
    Signal is emitted when there is change in Y right axis.
*/


DeclarativeBoxSet::DeclarativeBoxSet(const QString label, QObject *parent)
    : QBoxSet(label, parent)
{
    connect(this, SIGNAL(valuesChanged()), this, SIGNAL(changedValues()));
    connect(this, SIGNAL(valueChanged(int)), this, SIGNAL(changedValue(int)));
}

QVariantList DeclarativeBoxSet::values()
{
    QVariantList values;
    for (int i(0); i < 5; i++)
        values.append(QVariant(QBoxSet::at(i)));
    return values;
}

void DeclarativeBoxSet::setValues(QVariantList values)
{
    for (int i(0); i < values.count(); i++) {
        if (values.at(i).canConvert(QVariant::Double))
            QBoxSet::append(values[i].toDouble());
    }
}

// =====================================================

DeclarativeBoxPlotSeries::DeclarativeBoxPlotSeries(QDECLARATIVE_ITEM *parent) :
    QBoxPlotSeries(parent),
    m_axes(new DeclarativeAxes(this))
{
    connect(m_axes, SIGNAL(axisXChanged(QAbstractAxis*)), this, SIGNAL(axisXChanged(QAbstractAxis*)));
    connect(m_axes, SIGNAL(axisYChanged(QAbstractAxis*)), this, SIGNAL(axisYChanged(QAbstractAxis*)));
    connect(m_axes, SIGNAL(axisXTopChanged(QAbstractAxis*)), this, SIGNAL(axisXTopChanged(QAbstractAxis*)));
    connect(m_axes, SIGNAL(axisYRightChanged(QAbstractAxis*)), this, SIGNAL(axisYRightChanged(QAbstractAxis*)));
    connect(this, SIGNAL(hovered(bool, QBoxSet*)), this, SLOT(onHovered(bool, QBoxSet*)));
    connect(this, SIGNAL(clicked(QBoxSet*)), this, SLOT(onClicked(QBoxSet*)));
}

void DeclarativeBoxPlotSeries::classBegin()
{
}

void DeclarativeBoxPlotSeries::componentComplete()
{
    foreach (QObject *child, children()) {
        if (qobject_cast<DeclarativeBoxSet *>(child)) {
            QBoxPlotSeries::append(qobject_cast<DeclarativeBoxSet *>(child));
        } else if (qobject_cast<QVBoxPlotModelMapper *>(child)) {
            QVBoxPlotModelMapper *mapper = qobject_cast<QVBoxPlotModelMapper *>(child);
            mapper->setSeries(this);
        }
    }
}

QDECLARATIVE_LIST_PROPERTY<QObject> DeclarativeBoxPlotSeries::seriesChildren()
{
    return QDECLARATIVE_LIST_PROPERTY<QObject>(this, 0, &DeclarativeBoxPlotSeries::appendSeriesChildren LIST_PROPERTY_PARAM_DEFAULTS);
}

void DeclarativeBoxPlotSeries::appendSeriesChildren(QDECLARATIVE_LIST_PROPERTY<QObject> *list, QObject *element)
{
    // Empty implementation; the children are parsed in componentComplete instead
    Q_UNUSED(list);
    Q_UNUSED(element);
}

DeclarativeBoxSet *DeclarativeBoxPlotSeries::at(int index)
{
    QList<QBoxSet *> setList = boxSets();
    if (index >= 0 && index < setList.count())
        return qobject_cast<DeclarativeBoxSet *>(setList[index]);

    return 0;
}

DeclarativeBoxSet *DeclarativeBoxPlotSeries::insert(int index, const QString label, QVariantList values)
{
    DeclarativeBoxSet *barset = new DeclarativeBoxSet(label, this);
    barset->setValues(values);
    if (QBoxPlotSeries::insert(index, barset))
        return barset;
    delete barset;
    return 0;
}

void DeclarativeBoxPlotSeries::onHovered(bool status, QBoxSet *boxset)
{
    emit hovered(status, qobject_cast<DeclarativeBoxSet *>(boxset));
}

void DeclarativeBoxPlotSeries::onClicked(QBoxSet *boxset)
{
    emit clicked(qobject_cast<DeclarativeBoxSet *>(boxset));
}

#include "moc_declarativeboxplotseries.cpp"

QTCOMMERCIALCHART_END_NAMESPACE
