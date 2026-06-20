class Solution {
public:
    double angleClock(int hour, int minutes) {


        if(hour == 12) hour = 0;

        double res = abs((30 * (double)hour) - ((double)11 / 2) * (double)minutes);

        if(res >= 180) return (360 - res);
        return res;

    }
};