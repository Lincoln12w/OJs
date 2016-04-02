    #include <iostream>
    #include <map>
    #include <cstdio>

    using std::cin;
    using std::cout;
    using std::map;

    static void getinfo(map<int,double> & poly)
    {
        int n, k;
        double an;

        cin >> k;
        for(int i = 0; i < k; i++)
        {
            cin >> n >> an;
            poly[n] += an;
            if(poly[n] == 0)
                poly.erase(n);
        }
    }

    int main()
    {
        map<int, double> poly;
        
        getinfo(poly);
        getinfo(poly);
        cout << poly.size();
        if(poly.size())
            for(map<int,double>::reverse_iterator rviter=poly.rbegin(); rviter != poly.rend(); rviter++)
                printf(" %d %.1f",rviter->first,rviter->second);

        return 0;
    }
