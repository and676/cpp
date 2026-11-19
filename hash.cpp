unordered_set<string>s;
s.insert(str1);
s.insert(str2);
s.count("hello");//统计某个元素在集合中出现了多少次
s.size();
s.erase(str1);
s.clear();
s.empty();
unodered_map<string,string>map1;
map1[str1]="world";
map1.count("hello");
map1["hello"];
auto it=map1.find("hello");
if(it!=map1.end())
{cout<<it->second<<'\n';
}
map1.erase("hello");
map1.clear();
map1.rmpty();
map1.size();
unordered_map<int,int>mp;
mp[10]=100;
mp[20]=200;
cout<<mp[10]<<'\n';
if(mp.count){
	cout<<"yes\n";
	
}
mp.erase();

 struct student{
 	int age;
 	string name;
 	student(int a,string b)
 	{
 		age=a;
 		name=b;
	 }
 };
 students1(17,"zhangsan");
 student s2(17,"zhangsan");
 unordered_map<student*,string>map;
 map[&s1]="zhengshizhangsan";
 cout<<map.count(&s1)>0<<'\n';
 cout<<(map.count(&s3)>0)<<'\n';
 map[&s3]="zheshilingyigezhangsan";
 cout<<map.size()<<'\n';
 
 map<int,string>treemap;
 treemap[5]="zheshiwu";
 treemap[7]="zheshiqi";
 treemap[1]="zheshiyi";
 treemap[2]="zheshier";
 cout<<(treemap.count(1)!=0)<<'\n';
 cout<<(treemap.count(10)!=0)<<'\n';
 cout<<treemap[4]<<'\n';
 treemap[4]="zhangsanshi4";
 cout<<treemap[4]<<'\n';
 cout<<treemap.begin()->first<<'\n';
  auto it =mp.lower_bound(4);
  auto it=mp.upper_bound(4);
  auto it=treemap.upper_bound(4);
  --it;
  //找 小于等 于 4 的最大key
  auto it2 =treemap.lower_bound(4);
  if(it2!=treemap:end())
  {
  	coout<<it2->first<<'\n';
  	
	}  
	
  
