#include <iostream>
#include <ctime>
#include <string>
#include <istream>

using namespace std;

int main(){
    int x;
    cin>>x;

    time_t time1 = time(NULL);
    struct tm *ctm = localtime(&time1);

    int hr = ctm->tm_hour, min= ctm->tm_min;
    int ss[4] = {hr/10, hr%10, min/10, min%10};
    for(int i=0; i<4; i++){
        cout<<ss[(i+x)%4];
    }
    cout<<"\n";
    return 0;
}
