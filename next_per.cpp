void nxt_pr()
 {
      typedef std::vector<int> V; //<or_any_class>
      V v;

      for(int i=1;i<=5;++i)
        v.push_back(i*10);
      do{
            std::cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<" "<<v[4]<<std::endl;;
        }

       while(std::next_permutation(v.begin(),v.end()));
 }
