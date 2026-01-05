
#include <bits/stdc++.h>
using namespace std;
class WordDictionary {
public:
  struct wordNode {
    bool isEndofWord;
    wordNode *children[26];
  };
  wordNode *getWord() {
    wordNode *newNode = new wordNode();
    newNode->isEndofWord = false;
    for (int i = 0; i < 26; i++) {
      newNode->children[i] = NULL;
    }
    return newNode;
  }
  wordNode *root;
  WordDictionary() { root = getWord(); }

  void addWord(string word) {
    wordNode *crawler = root;
    for (int i = 0; i < word.length(); i++) {
      char ch = word[i];
      int idx = ch - 'a';
      if (crawler->children[idx] == NULL) {
        crawler->children[idx] = getWord();
      }
      crawler = crawler->children[idx];
    }
    crawler->isEndofWord = true;
  }
  bool helper(wordNode *node, int pos, string word) {

    if (pos == word.length()) {
      return node->isEndofWord;
    }
    char ch = word[pos];
    if (ch == '.') {
      for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL) {
          if (helper(node->children[i], pos + 1, word)) {
            return true;
          }
        }
      }
      return false;
    } else {
      int idx = ch - 'a';
      if (node->children[idx] == NULL)
        return false;
      return helper(node->children[idx], pos + 1, word);
    }
  }
  bool search(string word) { return helper(root, 0, word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */