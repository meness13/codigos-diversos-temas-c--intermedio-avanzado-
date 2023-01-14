#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const char *numbers = "0123456789";//[48-57]
const char *lower_case = "abcdefghijklmnopqrstuvwxyz";//[97-122]
const char *upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//[65-90]
const char *special_characters = "!@#$%^&*()-+";

// Complete the minimumNumber function below.
int minimumNumber(int n, const char *password) {
    // Return the minimum number of characters to make the password strong
    bool cs[4] = {false};


    for (int i=0; i<n; ++i){
        if(47<password[i] && password[i]<58){
            cs[0] = true;
        }else if(96<password[i] && password[i]<123){
            cs[1] = true;
        }else if(64<password[i] && password[i]<91){
            cs[2] = true;
        }else{
            cs[3] = true;
        }
    }
    int cont = 0;
    for(int i=0; i<4; ++i){
        if(!cs[i]){
            cont++;
        }
    }
    int pSz = strlen(password);

    if(pSz+cont>5){
        return cont;
    }

    return cont + 6-(pSz+cont);
}

int main(){
    int n = 5;
    const char *password = new char[n];
    password = "2bbbb";
    int answer = minimumNumber(n, password);

    cout<< answer << "\n";

    return 0;
}
