using System.Collections.Generic;
using System;
using System.Linq;

public class Test
{
	public static void Main()
	{
		// your code goes here
		var totalTestCases = Convert.ToInt32(Console.ReadLine());
		var answers = new List<int>();
		for(var counter = 0; counter <totalTestCases; counter++ ){
		    var testCase = Console.ReadLine();
		    var splitedNumbers = testCase.Split(' ');
		    answers.Add(Convert.ToInt32(splitedNumbers[0]) + Convert.ToInt32(splitedNumbers[1]) );
		}
		
		foreach(var answer in answers){
		    Console.WriteLine(answer);
		    
		}
	}
}
