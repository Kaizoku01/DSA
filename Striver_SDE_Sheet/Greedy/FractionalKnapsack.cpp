#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool comparision(Item a, Item b){
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

int Fknapsack(vector<Item> &arr, int Capacity){

    //sort acc to value/weight ratio
    sort(arr.begin(), arr.end(),comparision);
    
    int currentWeight = 0;
    double maxProfit = 0.0;

    for(int i=0;i<arr.size();i++){
        if(currentWeight + arr[i].weight <= Capacity){
            currentWeight += arr[i].weight;
            maxProfit += arr[i].value;
        }
        else{
            int remainingWeight = Capacity - arr[i].weight;

            maxProfit += (arr[i].value / (double)arr[i].weight) * (double)remainingWeight;
        }
    }
    return maxProfit;
}

int main() {
   int n = 3, Capacity = 50;
   vector<Item> arr = { {100,20},{60,10},{120,30} };
   double ans = Fknapsack(arr,Capacity);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}