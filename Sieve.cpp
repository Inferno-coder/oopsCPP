class Sieve{
    public:
    bool *isPrime;
    Sieve(int size){
    isPrime = new bool[size];
        for (int i = 0; i <= size; ++i) {
            isPrime[i] = true;
        }
    isPrime[0]=false;
    isPrime[1]=false;
    createSieve(size);
    };
    void createSieve(int n){
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]==true){
                for(int j=i*i;j<=n;j+=i)isPrime[j]=false;
            }
        }
    } 
};
