// This code solves a rat maze problem using recursion and backtracking.
// It takes a 2D array of integers representing the maze where 1 indicates a valid path and 0 indicates a blocked path.
// It then finds a path from the starting point (0,0) to the ending point (n-1, m-1) using depth-first search and backtracking.

import java.util.ArrayList;
import java.util.Scanner;

public class RatInAMazeNoMultipleIf {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of rows in the maze: ");
        int n = sc.nextInt();

        System.out.print("Enter the number of columns in the maze: ");
        int m = sc.nextInt();

        int[][] arr = new int[n][m];
        System.out.println("Enter the maze matrix (0s for blocked cells and 1s for open cells): ");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        sc.close();
        System.out.println(findPath(arr, n, m));
    }

    public static ArrayList<String> findPath(int[][] arr, int n, int m) {

        int[][] vis = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
            }
        }

        ArrayList<String> ans = new ArrayList<>();

        int x = 0;
        int y = 0;

        String s = "";

        // these are the indices for down, left, right, up for x and y axis.
        int[] dx = {1, 0, 0, -1};
        int[] dy = {0, -1, 1, 0};

        if (arr[0][0] != 0) solve(arr, vis, n, m, s, ans, x, y, dx, dy);
        return ans;
    }

    private static void solve(int[][] arr, int[][] vis, int n, int m, String s, ArrayList<String> ans, int x, int y, int[] dx, int[] dy) {

        if (x == n - 1 && y == m - 1) {
            ans.add(s);
            return;
        }
        // direction in which the rat movies
        String dir = "DLRU";

        // since we have four available direction
        for (int ind = 0; ind < 4; ind++) {
            int nextx = x + dx[ind];
            int nexty = y + dy[ind];

            // checks to verify if a rat can move in another cell
            if (nextx >= 0 && nexty >= 0 && nextx < n && nexty < m && vis[nextx][nexty] != 1 && arr[nextx][nexty] == 1) {
                vis[x][y] = 1;
                solve(arr, vis, n, m, s + dir.charAt(ind), ans, nextx, nexty, dx, dy);
                vis[x][y] = 0;
            }
        }
    }
}

// Time complexity: O(3^(n^2)) where n is the number of rows or columns in the maze, since in the worst case, each cell can have 3 possible directions to explore and the maximum number of cells in the maze is n^2.

// Space complexity: O(n^2), as we are creating a visited array of size n^2 to keep track of visited cells.