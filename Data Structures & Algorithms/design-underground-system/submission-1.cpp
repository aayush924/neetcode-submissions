class UndergroundSystem {
    unordered_map<int, pair<int, string>> checkIns;
    unordered_map<string, pair<double, int>> durations;
public:
    UndergroundSystem() {}
    void checkIn(int id, string stationName, int t) {
        checkIns[id]={t, stationName};
        return;
    }
    void checkOut(int id, string stationName, int t) {
        int checkInTime=checkIns[id].first;
        string checkInSt=checkIns[id].second;

        string journey=to_string(checkInSt.size())+'*'+checkInSt+"to"+stationName;
        
        if(durations.count(journey)){
            double time=0;
            int count=0;
            time=durations[journey].first;
            time+=t-checkInTime;
            count=durations[journey].second;
            count++;
            durations[journey]={time, count};
        }
        else{
            durations[journey]={t-checkInTime, 1};
        }
        return;
    }
    double getAverageTime(string startStation, string endStation) {
        string journey=to_string(startStation.size())+'*'+startStation+"to"+endStation; 
        double time=durations[journey].first;
        int count=durations[journey].second;
        return time/count;
    }
};
