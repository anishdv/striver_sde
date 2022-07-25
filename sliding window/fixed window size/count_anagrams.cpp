//https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

int search(string pat, string txt) {
	    int sizetxt=txt.size();
	    int k=pat.size();
	    int ans=0;
	    
	    // lets first keep the record of the characters in pat
	    vector<int> cntpat(26,0);
	    for (int i=0; i<k; i++){
	        cntpat[pat[i]-'a']++;
	    }
	    
	    int i=0;
	    int j=0;
	    vector<int> cnttxt(26,0);
	    
	    while(j<sizetxt){
	        cnttxt[txt[j]-'a']++;
	        if (j-i+1<k){
	            j++;
	        }
	        else{
	            if (cnttxt==cntpat) ans++; // we dont want n operations everytime for this so map should be used and a count varible should be maintained
	            cnttxt[txt[i]-'a']--;
	            i++;
	            j++;
	        }
	    }
	    return ans;
	}

int search(string pat, string txt) {
    string& s=txt;
	string& p=pat;
	unordered_map<char, int> mp;
    int ans = 0;
    
    //storing the occ. of string p in the map
    for (auto &x : p){
        mp[x]++;
    }

    int count = mp.size(); // count represents number of characters of pat need to found 
    int k = p.size();
    int i=0, j=0;

    while (j < s.size()){
        //calculation part
        if (mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if (mp[s[j]] == 0){
                count--;
            }
        }

        //window length not achived yet
        if (j-i+1 < k){
            j++;
        }

        //window length achived, find ans and slide the window
        else if (j-i+1 == k){
            //finding the ans
            if (count == 0){
                ans++;
            }
            if (mp.find(s[i]) != mp.end()){
                mp[s[i]]++;
                if (mp[s[i]] == 1){ // it was zero and it is made one so count should be increased
                    count++;
                }
            }

            //slide the window
            i++;
            j++;
        }
    }
    return ans;
}