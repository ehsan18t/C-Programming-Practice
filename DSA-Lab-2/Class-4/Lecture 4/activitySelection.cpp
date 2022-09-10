#include<bits/stdc++.h>
using namespace std;

struct activity{
    char name;
    int start;
    int end;
};

bool myFunction(activity a, activity b){
    return a.end<b.end;
}

void activitySelection(activity array[], int n){
    int currentActivity = 0;
    cout<< array[currentActivity].name << " ";
    for(int nextActivity=1; nextActivity<n;nextActivity++){
        if(array[currentActivity].end <= array[nextActivity].start){
            // cout<< array[nextActivity].name << " ";
            currentActivity=nextActivity;
            cout<< array[currentActivity].name << " ";
        }
    }
}
int main(){

    int numberofActivity;
    cin>>numberofActivity;

    struct activity array[numberofActivity];

    for(int i=0; i<numberofActivity;i++){
        cin>> array[i].name;
        cin>>array[i].start;
        cin>>array[i].end;
    }

    sort(array, array+numberofActivity, myFunction);

    // for(int i=0; i<numberofActivity;i++){
    //     cout<< array[i].name<< " ";
    //     cout<<array[i].start<< " ";
    //     cout<<array[i].end;
    //     cout<< endl;
    // }

    activitySelection(array, numberofActivity);

    return 0;
}