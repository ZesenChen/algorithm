#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Print(vector<vector<int> > a){
	for(int i = 0; i < a.size(); ++i ){
		for(int j = 0; j < a[i].size(); ++ j){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

//从一个不重复的数组中选择任意个下标不同的数加起来等于目标值，返回全部满足要求的子集 
class Sum2targetI{
public:
	vector<vector<int> > sumVector(vector<int> candidates, int target){
		dfs(candidates,0,target);
		return result;
	} 
	
	void dfs(vector<int> candidates, int start, int target){
		if(target<0) return;
		else if(target==0) result.push_back(tmp);
		else{
			for(int i = start; i < candidates.size(); ++ i){
				tmp.push_back(candidates[i]);
				dfs(candidates,i+1,target-candidates[i]);
				tmp.pop_back();
			}
		}
	}
private:
	vector<vector<int> > result;
	vector<int> tmp;
};

//从一个不重复的数组中选择任意个数加起来等于目标值,可选择重复的数字,返回全部满足要求的子集
class Sum2targetII{
public:
	vector<vector<int> > sumVector(vector<int> candidates, int target){
		dfs(candidates,0,target);
		return result;
	} 
	
	void dfs(vector<int> candidates, int start, int target){
		if(target<0) return;
		else if(target==0) result.push_back(tmp);
		else{
			for(int i = start; i < candidates.size(); ++ i){
				tmp.push_back(candidates[i]);
				dfs(candidates,i,target-candidates[i]);//与上一题目解法的唯一区别,可以重复选择同一数字 
				tmp.pop_back();
			}
		}
	}
private:
	vector<vector<int> > result;
	vector<int> tmp;
};

//从一个有重复元素的数组中选择任意个数加起来等于目标值,返回全部满足要求的子集,但子集之前不能相同 
class Sum2targetIII{
public:
	vector<vector<int> > sumVector(vector<int> candidates, int target){
		sort(candidates.begin(),candidates.end()); 
		dfs(candidates,0,target);
		return result;
	} 
	
	void dfs(vector<int> candidates, int start, int target){
		if(target<0) return;
		else if(target==0) result.push_back(tmp);
		else{
			for(int i = start; i < candidates.size(); ++ i){
				tmp.push_back(candidates[i]);
				dfs(candidates,i,target-candidates[i]);
				while(i<candidates.size()-1 && candidates[i+1]==candidates[i]) ++ i; 
				tmp.pop_back();
			}
		}
	}
private:
	vector<vector<int> > result;
	vector<int> tmp;
};

//从1到n这n个数字中选取k个数字,返回满足要求的全部子集 
class KNumSub{
public:
	vector<vector<int> > selKNum(int n, int k){
		dfs(n,k,1);
		return result;
	}

	void dfs(int n, int k, int start){
		if(k<0) return;
		else if(k==0) result.push_back(tmp);
		else{
			for(int i = start; i <= n; ++ i){
				tmp.push_back(i);
				dfs(n,k-1,i+1);
				tmp.pop_back();
			}
		}
	}
private:
	vector<vector<int> > result; 
	vector<int> tmp;
};

//给定一不重复的整数数组，返回它的全部子集 
class subset1{
public:
	vector<vector<int> > subVector(vector<int> set){
		sort(set.begin(),set.end());
		dfs(set,0);
		return result;
	}
	
	void dfs(vector<int> set, int start){
		result.push_back(tmp);
		for(int i = start; i < set.size(); ++ i){
			tmp.push_back(set[i]);
			dfs(set,i+1);
			tmp.pop_back();       
		}
	} 
private:
	vector<vector<int> > result;
	vector<int> tmp;
};

//给定一可能有重复元素的数组,返回它的全部子集,子集之间不能相同,且子集按字典序排列 
class subset2{
public:
	vector<vector<int> > subVector(vector<int> set){
		sort(set.begin(),set.end());
		dfs(set,0);
		return result;
	}
	
	void dfs(vector<int> set, int start){
		result.push_back(tmp);
		for(int i = start; i < set.size(); ++ i){
			tmp.push_back(set[i]);
			dfs(set,i+1);
			while(i<set.size()-1 && set[i+1]==set[i]) ++i;//把元素弹出来之前判断是否重复  
			tmp.pop_back();     
		}
	} 
private:
	vector<vector<int> > result;
	vector<int> tmp;
};

//给定一可能有重复元素的数组,返回它的全部子集,子集之间不能相同,且子集按size从小到大排列 
class subset3{
public:
	vector<vector<int> > subVector(vector<int> set){
		sort(set.begin(),set.end());
		for(int i = 0; i <= set.size(); ++ i)
			dfs(set,0,i);
		return result;
	}
	void dfs(vector<int> set, int start, int k){
		if(k<0) return;
		else if(k==0) result.push_back(tmp);
		else{
			for(int i = start; i < set.size(); ++ i){
				tmp.push_back(set[i]);
				dfs(set,i+1,k-1);
				tmp.pop_back();
			}
		}
	}
private:	
	vector<vector<int> > result;
	vector<int> tmp;
}; 


//无重复元素数组的组合问题 
class PermutationsI{
public:
	vector<vector<int> > permutations(vector<int> &num){
		sort(num.begin(),num.end());
		dfs(num,0);
		return result;
	}
	void dfs(vector<int> &num, int start){
		result.push_back(num);
		for(int i = start; i < num.size()-1; ++ i){
			for(int j = i+1; j < num.size(); ++ j){
				swap(num[i],num[j]);
				dfs(num,i+1);
				swap(num[i],num[j]); 
			}
		}
	}
private:
	vector<vector<int> > result;
};

//有重复元素数组的组合问题 
class PermutationsII{
public:
vector<vector<int> > permutations(vector<int> &num){
    vector<vector<int> > res;
    vector<int> vec=num;
    sort(num.begin(),num.end()); 
    do{
    	res.push_back(num);
        next_permutation(num.begin(),num.end());
    }while(num!=vec);
    return res;
}
};

int main(){
	int a[10] = {2,2,3,4};
	vector<int> b(a,a+4);
	Sum2targetIII test;
	vector<vector<int> > tmp = test.sumVector(b,6);
	Print(tmp);
	return 0;
} 
