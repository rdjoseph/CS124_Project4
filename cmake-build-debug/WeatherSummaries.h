//
// Created by RDJ on 11/5/2018.
//

#ifndef CS124PROJECT_4_WEATHERSUMMARIES_H
#define CS124PROJECT_4_WEATHERSUMMARIES_H
#include <algorithm>
#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <sstream>
#include <vector>

//To make <, >,

struct Date
{
    int year;
    int month;
    int day;
};

class WeatherSummary
{
private:
    std::string stationID, //The ID of the station that took the info
            location;  //The location of the collected informatio
    Date        date;      //The date of the weather summary
    double      precipitation, //Average precipitation on this date
            snowFall,      //Average snow fall on this date
            snowDepth;     //Average snow depth on this date
public:


    WeatherSummary(std::string inStationID, std::string inLocation, std::string inDate, double inPrecipitation, double inSnowFall, double inSnowDepth);


    //Getters for weather data

    std::string getStationID(); //Returns the station ID of the station that collected the weather data

    std::string getLocation(); //Returns the location of the weather summary

    Date getDate() const; //Returns the date of the weather summary

    double getPrecipitation(); //Returns the average precipitation on the Weather Summary

    double getSnowFall();  //Returns the average snow fall on the Weather Summary

    double getSnowDepth(); //Returns the snow depth on the Weather Summary

    friend bool operator <(const WeatherSummary &lhs, const WeatherSummary &rhs);

    friend bool operator >(const WeatherSummary &lhs, const WeatherSummary &rhs);

    friend bool operator ==(const WeatherSummary &lhs, WeatherSummary &rhs);

    friend std::ostream &operator <<(std::ostream& out, WeatherSummary weather);





};

void makeVector(std::vector<WeatherSummary>& weatherData, int size);


#endif //CS124PROJECT_4_WEATHERSUMMARIES_H
