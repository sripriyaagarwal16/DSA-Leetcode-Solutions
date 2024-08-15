class Solution {
public:
//time complexity : O(N*4 ^n)
//Space complexoty:O(4^n)
string combinations(int n ){
    if(n==2){
        return "abc";
    }
    if(n==3){
        return "def";
    }
    if(n==4){
        return "ghi";
    }
    if(n==5){
        return "jkl";
    }
    if(n==6){
        return "mno";
    }
    if(n==7){
        return "pqrs";
    }
    if(n==8){
        return "tuv";
    }
    if(n==9){
        return "wxyz";
    }
    return "";
}
int letterCombinationshelper(string digits,vector<string>&output){
    //base case:
    if(digits=="0"){
        output.push_back("");
        return 1;
    }
    int number=stoi(digits);
    int lastnumber=number%10;
    string smallstring=combinations(lastnumber);
    int smallnumber=number/10;
    string string_smallnumber=to_string(smallnumber);
    int smalloutputsize=letterCombinationshelper(string_smallnumber,output);
    int currentsize=smalloutputsize*smallstring.size();
    vector<string>temp_output(currentsize);
    for(int i=0;i<smallstring.size();i++){
        for(int j =0;j<smalloutputsize;j++){
            temp_output[i*smalloutputsize+j]=output[j];
        }
    }
    int k =0;
    for(int i=0;i<smallstring.size();i++){
        for(int j =0;j<smalloutputsize;j++){
            temp_output[k]=temp_output[k]+smallstring[i];
            k++;
        }
    }
    output=temp_output;
    return k;


}
vector<string> letterCombinations(string digits) {
    vector<string>output;
    if(digits==""){
       return output;
    }
    int outputsize=letterCombinationshelper( digits,output);
    return output;
}

};
