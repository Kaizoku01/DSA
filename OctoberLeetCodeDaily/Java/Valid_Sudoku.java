public class Valid_Sudoku {

	public class Solution_optimized {

	    // my thought is to use hashmap counting
	    // or maybe bitmap is better, less memory required
	    public boolean isValidSudoku(char[][] board) {

			final int SIZE = 9;

	        if(board == null || board.length != SIZE || board[0].length != SIZE) return false;

	        boolean[][] row = new boolean[SIZE][SIZE]; // i-th row, number j
	        boolean[][] col = new boolean[SIZE][SIZE];
	        boolean[][] matrix = new boolean[SIZE][SIZE];

	        for(int i = 0; i < SIZE; i++){
	            for(int j = 0; j < SIZE; j++){
	                if(board[i][j] == '.') continue;

	                // that number-1, is its index in every checking array
	                int n = board[i][j] - '1';

	                // check three array, if already set true
	                // sub-matrix index: i%3 + j%3
	                if(row[i][n] || col[j][n] || matrix[i - i % 3 + j / 3][n]){
	                    return false;
	                }

	                // if not set, now set this number exists
	                row[i][n] = true;
	                col[j][n] = true;
	                matrix[i - i % 3 + j / 3][n] = true;

	            }
	        }
	        return true;
	    }
	}
}
