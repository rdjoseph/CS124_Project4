//
// Created by RDJ on 11/5/2018.
//

#include "WeatherSummaries.h"

WeatherSummary::WeatherSummary(std::string inStationID, std::string inLocation, std::string inDate, double inPrecipitation, double inSnowFall, double inSnowDepth)
{
    stationID = inStationID;
    location = inLocation;
    precipitation = inPrecipitation;
    snowFall = inSnowFall;
    snowDepth = inSnowDepth;
    //Put Date together by splitting inDate string into substrings and converting to ints
    std::stringstream ss(inDate);
    std::string item;
    char delimeter = '-';
    std::vector<std::string> splittedStrings;
    while (getline(ss, item, delimeter))
    {
        splittedStrings.emplace_back(item);
    }
    date.year = atoi((splittedStrings.at(0)).c_str());
    date.month = atoi((splittedStrings.at(1)).c_str());
    date.day = atoi((splittedStrings.at(2)).c_str());
};

//Getters for weather data

std::string WeatherSummary::getStationID() //Returns the station ID of the station that collected the weather data
{
    return stationID;
};

std::string WeatherSummary::getLocation() //Returns the location of the weather summary
{
    return location;
};

Date WeatherSummary::getDate() const //Returns the date of the weather summary
{
    return date;
};

double WeatherSummary::getPrecipitation() //Returns the average precipitation on the Weather Summary
{
    return precipitation;
};

double WeatherSummary::getSnowFall() //Returns the average snow fall on the Weather Summary
{
    return snowFall;
};

double WeatherSummary::getSnowDepth() //Returns the snow depth on the Weather Summary
{
    return snowDepth;
};


bool operator <(const WeatherSummary &lhs, const WeatherSummary &rhs)
{
    if(lhs.getDate().year < rhs.getDate().year)
    {
        return true;
    }
    else if(lhs.getDate().month < rhs.getDate().month)
    {
        return true;
    }
    else if(lhs.getDate().day < rhs.getDate().day)
    {
        return true;
    }

    return false;
};

bool operator >(const WeatherSummary &lhs, const WeatherSummary &rhs)
{
    if(lhs.getDate().year > rhs.getDate().year)
    {
        return true;
    }
    else if(lhs.getDate().month > rhs.getDate().month)
    {
        return true;
    }
    else if(lhs.getDate().day > rhs.getDate().day)
    {
        return true;
    }

    return false;
};

bool operator ==(const WeatherSummary &lhs, WeatherSummary &rhs)
{
    if(lhs.getDate().year == rhs.getDate().year && lhs.getDate().month == rhs.getDate().month && lhs.getDate().day == rhs.getDate().day)
    {
        return true;
    }
    return false;
};

std::ostream &operator <<(std::ostream& out, WeatherSummary weather)
{
    out << std::left << std::setw(15) << weather.getStationID();
    out << std::right << std::setw(25) << weather.getLocation();
    out << std::setw(15) << weather.getDate().year << "-" << weather.getDate().month << "-" << weather.getDate().day;
    out << std::setw(11) << weather.getPrecipitation();
    out << std::setw(11) << weather.getSnowFall();
    out << std::setw(10) << weather.getSnowDepth();
    out << std::endl;
};


//OTHER FUNCTIONS THAT ARE NOT PART OF THE WEATHER SUMMARY CLASS

void printVector(std::vector<WeatherSummary>& weatherData, std::ostream& out)
{
    for(int i = 0; i < weatherData.size(); i++)
    {
        out << weatherData.at(i);
    }
}

void makeVector(std::vector<WeatherSummary>& weatherData, int size)
{
    std::vector<WeatherSummary> processVector;
    std::string  station = "",       //Station ID
            location = "",      //Location of taken data
            junk = "",          //For forcing program to read newline character
            date = "";          //Date weather data taken
    double precipitation = 0.0, //Precipitation average
            snowFall = 0.0,     //Snow fall average
            snowDepth = 0.0;    //Snow depth average
    char   comma;               //For processing commas in CSV

    std::ifstream f_in;
    f_in.open("BurlWeather2014-2017.csv");
    //Get first line and toss it because it's just labels
    f_in.ignore(100, '\n');
    while (f_in && f_in.peek() != EOF)
    {
        //Get the info
        getline(f_in, station, ',');
        getline(f_in, location, ',');
        getline(f_in, date, ',');
        f_in >> precipitation;
        f_in >> comma;
        f_in >> snowFall;
        f_in >> comma;
        f_in >> snowDepth;
        getline(f_in, junk);
        //Make the new object inside the vector itself
        processVector.emplace_back(WeatherSummary(station,location,date,precipitation,snowFall,snowDepth));
    }
    f_in.close();




    unsigned seed = 8675309; //I don't want true randomness, so I'm going to use a fixed seed.
    std::default_random_engine e(seed);
    shuffle(processVector.begin(),processVector.end(), e);

    //Loop through and emplace desired number onto passed in pointer
    for(int i = 0; i < size; i++)
    {
        weatherData.emplace_back(processVector.at(i));
    }


};

void makeVectors(std::vector<std::vector<WeatherSummary>>& compilation)
{
    //Start with empty vector of vectors, add a vector to it, and modify that vector to have the data
    //By using (i+1)*100, which should work out to 100, 200, 300, etc
    for(int i = 0; i < 10; i++)
    {
        compilation.emplace_back(std::vector<WeatherSummary>()); //Make an empty vector of weather summaries and emplace it back
        makeVector(compilation.at(i),((i+1)*100)); //Modify it inside the compilation vector
    }
}

