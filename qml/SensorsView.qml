import QtQuick 2.0
import QtQuick.Window 2.2

Column {
    property int defaultMargin: Screen.pixelDensity*2
    property int defaultWidth: Screen.pixelDensity*40
    width: defaultWidth
    height: Screen.pixelDensity*40
    anchors.leftMargin: defaultMargin
SensorLine{
    id: tempSensor
    valueText: sensorTemp.value
    parameterText: sensorTemp.parameter
}
SensorLine{
    id: distanceSensor
    valueText: sensorDistance.value
    parameterText: sensorDistance.parameter
}
SensorLine{
    id: voltageSensor
    valueText: sensorVoltage.value
    parameterText: sensorVoltage.parameter
}
}
