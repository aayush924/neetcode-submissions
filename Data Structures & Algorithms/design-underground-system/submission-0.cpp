class UndergroundSystem {
    unordered_map<int, pair<int, string>> checkIns;
    unordered_map<string, vector<int>> durations;
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
        durations[journey].push_back(t-checkInTime);
        return;
    }
    double getAverageTime(string startStation, string endStation) {
        string journey=to_string(startStation.size())+'*'+startStation+"to"+endStation; 
        vector<int> duration=durations[journey];
        double average=0;
        for(int& time: duration ){
            average+=time;
        }
        return average/duration.size();
    }
};
