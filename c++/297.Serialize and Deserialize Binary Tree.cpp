/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:

	void serializeHelp(TreeNode* root, vector<TreeNode*> &v){
		if(root == NULL){
			v.push_back(NULL);
		}else{
			v.push_back(root);
			serializeHelp(root->left, v);
			serializeHelp(root->right, v);
		}
	}

	TreeNode* deserializeHelp(vector<TreeNode*> &v, int &index){
		if(index >= v.size()) return NULL;
		TreeNode *root = v[index++];
		if(root){
			root->left = deserializeHelp(v, index);
			root->right = deserializeHelp(v, index);
		}
		return root;
	}

	void split(const string &s, char delim, vector<TreeNode*> &elems){
		stringstream ss(s);
		string item;
		while(getline(ss, item, delim)){
			TreeNode* node = (item == "#" ? NULL : new TreeNode(stoi(item)));
			elems.push_back(node);
		}
	}

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        vector<TreeNode*> v;
        serializeHelp(root, v);
        for(int i = 0; i < v.size(); i++){
        	result = result + (v[i] == NULL ? "#" : to_string(v[i]->val)) + " ";
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> v;
        split(data, ' ', v);
        int index = 0;
        return deserializeHelp(v, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));