/* The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
    //   return p[0].petrol;
      
//        i am iterating and checking the value of how much i  can go more
        int sum=0,r=0,d=0;
        for(int i=0;i<n;i++){
            sum+=(p[i%n].petrol-p[i%n].distance);
            if(sum<0){
//               if the 
                r=(i%n)+1;
                d+=sum;
                sum=0;
            }
        }
        if(sum+d>=0)return r;
        return -1;
    }
};
