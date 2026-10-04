class Solution {
public:
    bool checkValidString(string s) {
         
         stack<pair<char,int>>opening;
         stack<pair<char,int>>star;
         for(int i=0;i<s.size();i++){
            if(s[i]=='(')opening.push({'(',i});
           else if(s[i]=='*')star.push({'*',i});
            else{
                   if(!opening.empty())opening.pop();
                   else if(!star.empty())star.pop();
                   else return false;
            }
         }
        
            if(opening.empty())return true;
        else if(s.empty() && !opening.empty())return false;

    else{
        while(!star.empty() && !opening.empty() && star.top().second>opening.top().second){
        //pair<char,int>top1=star.top();
        star.pop();

        // pair<char,int>top2=opening.top();
        opening.pop();
        //    int index_of_star=top1.second;
        //    int index_of_opening=top2.second;
           

        }
    }
       

            if(opening.empty())return true;
         return false;
      

    }
};