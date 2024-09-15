#include<bits/stdc++.h>

using namespace std;

struct item{
	string name;
	int value;
	int weight;
	float ratio;
};


float frac_knap ( item arr[], int n, int knapsackWeight){

	float knapsackValue = 0.0;
	int rem = knapsackWeight;
	for(int i=0;i<n;i++){ /// Whole Object
		if(rem>=arr[i].weight){
			knapsackValue += arr[i].value;
			rem -= arr[i].weight;
			cout << arr[i]. name << " ";
		}
		else{ /// Fraction of the Object
			// float fraction = (float)knapsackWeight/arr[i].weight;
			knapsackValue = knapsackValue + (arr[i].ratio * rem);
			cout << arr[i]. name << " ";
			break;
		}
	}
	return knapsackValue;
}


bool compare (item a, item b){
	return a.ratio > b.ratio;
}


int main(){
	int n, knapsackWeight;
	cin>>n >> knapsackWeight;

	struct item itemset [n];
	//cin.ignore()
	for(int i=0; i<n; i++){
		//getline(cin, itemset[i].name);
		cin>> itemset[i].name;
		cin>> itemset[i].weight;
		cin>> itemset[i].value;
		itemset[i].ratio = (float)(itemset[i].value/itemset[i].weight);
	}
	cout << endl;
	sort(itemset,itemset+n, compare);
	cout << endl << frac_knap(itemset,n, knapsackWeight);
	return 0;
}

