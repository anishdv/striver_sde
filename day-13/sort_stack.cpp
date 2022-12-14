// this is solution to https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

void sortedInsert(stack<int> &s, int num){
    //base case => stack empty/ sbse bda element insert krna hai
    if(s.empty() || (!s.empty() && s.top() <num )){
        //seg fault de skta hai 2nd condn
        //seedhe push kar do
        s.push(num);
        return;
    }
    //aage bado to no. ko side me rakh rahe
    int n = s.top();
    s.pop();    //side me
    
    //rec call
    sortedInsert(s,num);
    //wapas jate hue n ko lete jao jo side me rakha tha
    s.push(n);
    
}
void sortStack(stack<int> &s)
{
    //base case
    if(s.size()==1){
        //wapas aa jana hai
        return;
    }
    //aage jao to upar wala side me rakho
    int num = s.top();
    s.pop();    //side me
    
    //rec call
    sortStack(s);
    
    //wapas aao jab do sortedInsert
    sortedInsert(s,num);
}