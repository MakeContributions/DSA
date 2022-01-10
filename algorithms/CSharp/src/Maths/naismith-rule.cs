using System;
using System.Collections.Generic;

namespace Algorithms.Maths
{
    public class NaismithsRule
    {
        public static double ReturnTime(int pathLenght, int upHill)
        {
            double timeCalculation = (pathLenght / 65) + (upHill / 10);
            Math.Round(timeCalculation);

            return timeCalculation;
        }

        public static void PrintInfo(string locationStart, string locationEnd, int pathLenght, int upHill)
        {
            double calculateKilometers = (double)pathLenght / 1000;
            string displayTwoDecimals = String.Format("{0:0.##}", calculateKilometers);

            double time = ReturnTime(pathLenght, upHill);

            int exactHour = (int)time / 60;
            int exactMinutes = (int)time - (exactHour * 60);

            Console.WriteLine("Start: " + locationStart + " ---> End: " + locationEnd + "\nDistance: " + pathLenght
                    + " meters or " + displayTwoDecimals + " kilometers.\nUphill distance: " + upHill + " meters.");
            if (exactHour > 1)
            {
                Console.WriteLine("Time required: " + exactHour + " hours and " + exactMinutes + " minutes.\n");
            }
            else if (exactHour == 0)
            {
                Console.WriteLine("Time required: " + exactHour + " hour and " + exactMinutes + " minutes.\n");
            }
            else
            {
                Console.WriteLine("Time required: " + time + " minutes.\n");
            }
        }

        public static void NaisMithRule(string locationStart, string locationEnd, int pathLenght, int UpHill, int DownHill)
        {
            double timeCalculation = (pathLenght / 65) + (UpHill / 10);
            Math.Round(timeCalculation);

            if (String.Equals(locationStart, locationEnd)) // Looping path
            {
                PrintInfo(locationStart, locationEnd, pathLenght, UpHill);
                Console.WriteLine("-----------------------------------------------------\n");
            }
            else // Not looping path
            {
                PrintInfo(locationStart, locationEnd, pathLenght, UpHill);
                PrintInfo(locationEnd, locationStart, pathLenght, DownHill);
                Console.WriteLine("-----------------------------------------------------\n");
            }
        }

        /* NaisMith's Rule is the total walking time that is equal to the time of crossing the distance to the level from
        point A to point B at a constant speed of 65 meters per minute (~ 4Km / h) + a delay of 1 minute for every 
        10 meters of ascent.
        In practice, the results of Naismith's rule are usually considered the minimum time necessary to complete a route. */

        public static void Main()
        {
            NaisMithRule("New York", "Washington", 120421, 1203, 531); // Test Case 1
            NaisMithRule("London", "York", 111091, 7100, 9801); // Test Case 2
            NaisMithRule("Rome", "Napoli", 81112, 2112, 1411); // Test Case 3
            NaisMithRule("Athens", "Athens", 20000, 481, 222); // Test Case 4 -> Looping Path
        }
    }
}