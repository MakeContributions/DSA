/*

*/


namespace Algorithms.Maths
{
    public class Matrix
    {
        public static int diagonalDifference(List<List<int>> arr)
        {
            int firstDiagonal = 0;
            int secondDiagonal = 0;
            int longitud = Convert.ToInt32(arr.LongCount());
            int total = 0;

            for (int i =0; i < longitud; i++){
                firstDiagonal += arr[i][i];
                secondDiagonal += arr[i][(longitud)-1-i];
            }

            total = firstDiagonal - secondDiagonal;
            if (total < 0) {
                total = total * (-1);
            }
            return total;
        }

    }



     class Solution
    {
        public static void Main(string[] args)
        {
           
            int n = Convert.ToInt32(Console.ReadLine().Trim());

            List<List<int>> arr = new List<List<int>>();

            for (int i = 0; i < n; i++)
            {
                arr.Add(Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList());
            }

            int result = Matrix.diagonalDifference(arr);

            Console.WriteLine(result);

            
        }   
    }
}

