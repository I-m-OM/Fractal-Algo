#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<double>> allCalcApproxIntegerNSR(int n, vector<vector<double>> intensity) {
    vector<vector<double>> ans(n, vector<double>(3, 0));

    for (int i=1; i<n; i++) {
        int npn = n*(n-i)*2;
        ans[i][0] = i;
        ans[i][1] = npn;
        // cout<<i<<" "<<npn<<"\n";
    }
    for (int i=1; i<n; i++) {
        for (int j=i; j<n; j++) {
            int distance = sqrt(i*i + j*j);
            if (distance >= n-1) distance = n-1;
            int npn = (n-j)*(n-i)*2;
            if (i != j) npn *= 2;
            ans[distance][1] += npn;
            // cout<<distance<<" "<<npn<<"\n";
        }
    }

    map<int, double> map;
    for (auto i:ans) {
        map[i[0]] = 0;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                for (int l=0; l<n; l++) {
                    if (i != k || j != l) {
                        int distance = sqrt((i-k)*(i-k) + (j-l)*(j-l)); 
                        if (distance >= n-1) distance = n-1;
                        map[distance] += abs(intensity[i][j] - intensity[k][l]);
                    }  
                }  
            }  
        }  
    }
    int index = 0;
    for (auto i:map) {
        if (index == 0) {
            index++;
            continue;
        }
        i.second /= 2;
        i.second /= ans[index][1];
        ans[index][2] = i.second;
        index++;
    }
    return ans;
}
 
vector<vector<double>> allCalcRealDecimalNSR(int n, vector<vector<double>> intensity) {
    vector<vector<double>> ans;
    for (double i=1; i<n; i++) {
        double npn = n*(n-i)*2;
        ans.push_back({i, npn, 0});
    }
    for (int i=1; i<n; i++) {
        for (int j=i; j<n; j++) {
            double value = sqrt(i*i + j*j);
            double npn = (n-j)*(n-i)*2;
            if (i != j) 
                npn *= 2;
            ans.push_back({value, npn, 0});
        }
    }
    sort(ans.begin(), ans.end());
    map<double, double> map;
    for (auto i:ans) {
        map[i[0]] = 0;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                for (int l=0; l<n; l++) {
                    if (i != k || j != l) {
                        double dist = sqrt((i-k)*(i-k) + (j-l)*(j-l)); 
                        map[dist] += abs(intensity[i][j] - intensity[k][l]);
                    }  
                }  
            }  
        }  
    }
    int index = 0;
    for (auto i:map) {
        i.second /= 2;
        i.second /= ans[index][1];
        ans[index][2] = i.second;
        index++;
    }
    return ans;
}

bool isInsideCarpet(int x, int y, int n) {
    while (n > 0) {
        if (x % 3 == 1 && y % 3 == 1) // Middle square is removed
            return false;
        x /= 3;
        y /= 3;
        n--;
    }
    return true;
}

// Function to generate the Sierpinski carpet matrix of size n
vector<vector<double>> generateSierpinskiCarpet(int n) {
    double size = pow(3, n);
    vector<vector<double>> carpet(size, vector<double>(size, 0)); // Initialize matrix with zeros

    // Fill the matrix with appropriate values based on Sierpinski carpet pattern
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (isInsideCarpet(i, j, n))
                carpet[i][j] = 255;
        }
    }
    return carpet;
}

// Function to print the matrix
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val == 0) cout << "---" << " ";
            else cout << val << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout<<"Size of matrix : ";
    cin>>n;
    
    vector<vector<double>> intensity(n, vector<double>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>intensity[i][j];
        }
    }
    vector<vector<double>> value1 = allCalcApproxIntegerNSR(n, intensity);
    vector<vector<double>> value2 = allCalcRealDecimalNSR(n, intensity);

    cout<<"\nMatrix Image : \n\n";
    printMatrix(intensity);

    cout<<"\n\n";

    int m;
    cout<<"Enter no. of iterations of carpet : ";
    cin>>m;
    vector<vector<double>> carpet = generateSierpinskiCarpet(m);
    vector<vector<double>> carpetData1 = allCalcApproxIntegerNSR(pow(3,m), carpet);
    vector<vector<double>> carpetData2 = allCalcRealDecimalNSR(pow(3,m), carpet);
    cout<<"\nCarpet Image : \n\n";
    printMatrix(carpet);

    cout<<"\n\n";

    cout<<"Approx Integer Results(matrix) : \n";
    for (auto i:value1)
        cout<<i[0]<<" | "<<i[1]<<" | "<<i[2]<<"\n";
    cout<<"\nReal Decimal Results(matrix) : \n";
    for (auto i:value2)
        cout<<i[0]<<" | "<<i[1]<<" | "<<i[2]<<"\n";

    cout<<"\n\n";

    cout<<"Approx Integer Results(carpet) : \n";
    for (auto i:carpetData1)
        cout<<i[0]<<" | "<<i[1]<<" | "<<i[2]<<"\n";
    cout<<"\nReal Decimal Results(carpet) : \n";
    for (auto i:carpetData2)
        cout<<i[0]<<" | "<<i[1]<<" | "<<i[2]<<"\n";
	return 0; 
}