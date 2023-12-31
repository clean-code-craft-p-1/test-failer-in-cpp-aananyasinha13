#pragma once
#include <string>
#include <assert.h>

namespace WeatherSpace {

    class IWeatherSensor {
    public:
        virtual double TemperatureInC() const = 0;
        virtual int Precipitation() const = 0;
        virtual int Humidity() const = 0;
        virtual int WindSpeedKMPH() const = 0;
    };
    /// <summary>
    /// This is a stub for a weather sensor. For the sake of testing 
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development
    /// </summary>
    class SensorStub : public IWeatherSensor {
        int Humidity() const override;

        int Precipitation() const override;

        double TemperatureInC() const override;

        int WindSpeedKMPH() const override;
    };

    class HighPrecipitationStub : public SensorStub {

        int Precipitation() const override;

        int WindSpeedKMPH() const override;
    };


    std::string Report(const IWeatherSensor& sensor);

    void TestRainy();

    void TestHighPrecipitation();
}

namespace TestWeatherSpace {

    void testForWeatherReport();
}
