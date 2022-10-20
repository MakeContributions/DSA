<script>
/* Javascript program to solve Rat in
a Maze problem using backtracking */

// Size of the maze
let N;

/* A utility function to print
	solution matrix sol[N][N] */
function printSolution(sol)
{
	for (let i = 0; i < N; i++) {
			for (let j = 0; j < N; j++)
				document.write(
					" " + sol[i][j] + " ");
			document.write("<br>");
		}
}

/* A utility function to check
		if x, y is valid index for N*N maze */
function isSafe(maze,x,y)
{
	// if (x, y outside maze) return false
		return (x >= 0 && x < N && y >= 0
				&& y < N && maze[x][y] == 1);
}

/* This function solves the Maze problem using
	Backtracking. It mainly uses solveMazeUtil()
	to solve the problem. It returns false if no
	path is possible, otherwise return true and
	prints the path in the form of 1s. Please note
	that there may be more than one solutions, this
	function prints one of the feasible solutions.*/
function solveMaze(maze)
{
	let sol = new Array(N);
	for(let i=0;i<N;i++)
	{
		sol[i]=new Array(N);
		for(let j=0;j<N;j++)
		{
			sol[i][j]=0;
		}
	}

		if (solveMazeUtil(maze, 0, 0, sol) == false) {
			document.write("Solution doesn't exist");
			return false;
		}

		printSolution(sol);
		return true;
}
/* A recursive utility function to solve Maze
	problem */
function solveMazeUtil(maze,x,y,sol)
{
	// if (x, y is goal) return true
		if (x == N - 1 && y == N - 1
			&& maze[x][y] == 1) {
			sol[x][y] = 1;
			return true;
		}

		// Check if maze[x][y] is valid
		if (isSafe(maze, x, y) == true) {
			// Check if the current block is already part of solution path.
			if (sol[x][y] == 1)
				return false;
			
			// mark x, y as part of solution path
			sol[x][y] = 1;

			/* Move forward in x direction */
			if (solveMazeUtil(maze, x + 1, y, sol))
				return true;

			/* If moving in x direction doesn't give
			solution then Move down in y direction */
			if (solveMazeUtil(maze, x, y + 1, sol))
				return true;
			
			/* If moving in y direction doesn't give
			solution then Move backwards in x direction */
			if (solveMazeUtil(maze, x - 1, y, sol))
				return true;

			/* If moving backwards in x direction doesn't give
			solution then Move upwards in y direction */
			if (solveMazeUtil(maze, x, y - 1, sol))
				return true;

			/* If none of the above movements works then
			BACKTRACK: unmark x, y as part of solution
			path */
			sol[x][y] = 0;
			return false;
		}

		return false;
}

let maze=[[ 1, 0, 0, 0 ],
						[ 1, 1, 0, 1 ],
						[ 0, 1, 0, 0 ],
						[ 1, 1, 1, 1 ] ];
N = maze.length;
solveMaze(maze);
</script>
