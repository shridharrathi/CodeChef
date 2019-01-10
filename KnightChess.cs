using System.Collections.Generic;
using System;
using System.Linq;
public class Test
{
	public static void Main()
	{
		// your code goes here
		var dict = new Dictionary<string, List<string>>();

	dict.Add("topLeft", new List<string> {"-23","03", "-32", "12", "-11","-30","10","-2-1","0-1"});	
	dict.Add("top", new List<string> {"-13","13","-22", "22","01","-20","20","-1-1","1-1"});	
	dict.Add("topRight", new List<string> {"03", "23","-12", "32","11","-10","30","0-1","2-1"});	
	dict.Add("left", new List<string> {"-22", "02","-31","11","-10","-3-1","1-1","-2-2","0-2"});	
	dict.Add("right", new List<string> {"02","22", "-11","31","10","-1-1","3-1","0-2","2-2"});	
	dict.Add("bottomLeft", new List<string> {"-21","01","-30","10","-1-1","-3-2","1-2","-2-3","0-3"});	
	dict.Add("bottom", new List<string> {"-11","11","-20","20","0-1","-2-2","2-2","-1-3","1-3"});	
	dict.Add("bottomRight", new List<string> {"01", "21","-10","30","1-1","-1-2","3-2","0-3","2-3"});
	
	
	var  totalTestCases = Convert.ToInt32(Console.ReadLine());
	for(int counter = 0; counter < totalTestCases; counter ++){
			var totalKnights = Convert.ToInt32(Console.ReadLine());
			//6; // Console.ReadLine();
			var knightPositions = new List<Position>();
			for(int knightCounter = 0; knightCounter < totalKnights; knightCounter++ )
			{
				var pos = Console.ReadLine();
				//mockInput[knightCounter];// console.ReadLine();
				var tests = pos.Split(' ');
				knightPositions.Add(new Position(Convert.ToDouble(tests[0]), Convert.ToDouble(tests[1])));	
		
			}
		
			var kingPositionInput =  Console.ReadLine();
			//"3 2";// Console.ReadLine();
			var kingPositionSplitedString = kingPositionInput.Split(' ');
			var kingsPosition = new Position(Convert.ToDouble(kingPositionSplitedString[0]), Convert.ToDouble(kingPositionSplitedString[1]));
			var positionDifferences = new List<string>();
			foreach(var position in knightPositions){
				var diffPositions = Extensions.GetDiff(kingsPosition, position);
				if(diffPositions.X <= 3 && diffPositions.X >= -3 && diffPositions.Y <= 3 && diffPositions.Y  >= -3 ){
					positionDifferences.Add($"{diffPositions.X}{diffPositions.Y}");
				}				
			}
			var isCheckMate = "YES";
		
			foreach(var key in dict.Keys){
			
			 	if(!dict[key].Select(i => i.ToString()).Intersect(positionDifferences).Any()){
					isCheckMate = "NO";
					//Console.WriteLine($"{dict[key].Select(i => i.ToString()).Intersect(positionDifferences).Count()}, {positionDifferences}");
					break;
				}
			}
			Console.WriteLine(isCheckMate);
	}
	}
	
}

public static class Extensions{
public static Position GetDiff(Position firstposition, Position secondPosition){
	return new Position(firstposition.X - secondPosition.X, firstposition.Y - secondPosition.Y);
}
}


// Define other methods and classes here

public class Position{
	public double X {get; set;}
	public double Y {get; set;}

	public Position (double x, double y){
		X = x;
		Y = y;
	}
}
