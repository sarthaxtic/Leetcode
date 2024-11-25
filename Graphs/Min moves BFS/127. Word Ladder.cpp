class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
// Create a set of all words in the word list for quick lookup.
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // Check if endWord is in the word list. If not, return 0.
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        // Use a queue to perform BFS (Breadth-First Search).
        queue<string> wordQueue;
        wordQueue.push(beginWord);

        // Distance from the beginWord (initially 0).
        int distance = 1;

        while (!wordQueue.empty()) {
            int size = wordQueue.size();
            distance++;  // Increase distance at each level of BFS

            while (size-- > 0) {
                string currWord = wordQueue.front();
                wordQueue.pop();

                // Try changing each character of the current word
                for (int i = 0; i < currWord.length(); i++) {
                    string temp = currWord;

                    for (char j = 'a'; j <= 'z'; j++) {
                        temp[i] = j;

                        // If the new word matches the endWord, return the distance
                        if (temp == endWord) return distance;

                        // If the new word is in the set, add it to the queue and remove it from the set
                        if (wordSet.find(temp) != wordSet.end()) {
                            wordQueue.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
        }
    }
};

        return 0; // Return 0 if no transformation sequence is found
