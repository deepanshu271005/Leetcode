class Solution {
public:
    struct state {
        int ratPos;
        int catPos;
        int turn; //-> 0 means rat, 1 means cat
        int steps;
    };

    // Note the 4D vector here!
    int dfs(state& s, vector<vector<vector<vector<int>>>>& dp, vector<vector<int>>& graph) {
        int ratP = s.ratPos;
        int catP = s.catPos;
        int turn = s.turn;
        int steps = s.steps;
        
        if (steps >= 200)
            return 0; // Draw by step limit
        if (ratP == 0)
            return 1; // Mouse wins
        if (catP == ratP)
            return 2; // Cat wins
            
        // Return exactly what was computed
        if (dp[ratP][catP][turn][steps] != -1)
            return dp[ratP][catP][turn][steps]; 

        if (turn == 0) {
            // Rat moves
            bool candraw = false;
            for (auto i : graph[ratP]) {
                state newstate = {i, catP, 1, steps + 1}; // fixed typo here
                int temp = dfs(newstate, dp, graph);
                
                // Rat takes a guaranteed win immediately
                if (temp == 1) return dp[ratP][catP][turn][steps] = 1;
                // Keep track if a draw is possible
                if (temp == 0) candraw = true;
            }
            // If no win was found, take the draw if possible. Otherwise, Cat wins (2).
            if (candraw) return dp[ratP][catP][turn][steps] = 0;
            return dp[ratP][catP][turn][steps] = 2;
            
        } else {
            // Cat moves
            bool candraw = false;
            for (auto i : graph[catP]) {
                if (i == 0)
                    continue; // cant go in the hole
                state newstate = {ratP, i, 0, steps + 1};
                int temp = dfs(newstate, dp, graph);
                
                // Cat takes a guaranteed win immediately
                if (temp == 2) return dp[ratP][catP][turn][steps] = 2;
                // Keep track if a draw is possible
                if (temp == 0) candraw = true;
            }
            // If no win was found, take the draw if possible. Otherwise, Mouse wins (1).
            if (candraw) return dp[ratP][catP][turn][steps] = 0;
            return dp[ratP][catP][turn][steps] = 1;
        }
    }

    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        state initial = {1, 2, 0, 0};
        
        // Initialize 4D DP: [ratPos][catPos][turn][steps]
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(n, vector<vector<int>>(2, vector<int>(205, -1)))
        );
        
        return dfs(initial, dp, graph);
    }
};