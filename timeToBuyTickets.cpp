class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sec=0,sz=tickets.size();
        int loop=true;
        while(loop){
           for(int i=0;i<sz && loop;i++){
            if(tickets[i]>0){
                sec++;
                tickets[i]--;
            }
            if(tickets[k]==0){
                loop=false;
                break;
            }
           }
        }
        return sec;
    }
};
