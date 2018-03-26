
public class BinarySearch {
static int dexNum = 0;
static int topCut = 0;
static int botCut = 0;
static int middle = 0;

	public static void main(String[] args) {
		String[] dex = getDex();
		
		for (int x = 0; x < (dex.length - 1); x++)
        {
            System.out.println(x + 1 + " " + dex[x]);
        }
		
		System.out.println(binarySearch(dex, "Wigglytuff"));

	}

	private static String[] getDex() {
		String dex[] = {"Bulbasaur","Ivysaur","Venusaur","Charmander","Charmeleon","Charizard","Squirtle","Wartortle","Blastoise","Caterpie","Metapod","Butterfree","Weedle","Kakuna","Beedrill","Pidgey","Pidgeotto","Pidgeot","Rattata","Raticate","Spearow","Fearow","Ekans","Arbok","Pikachu","Raichu","Sandshrew","Sandslash","NidoranF","Nidorina","Nidoqueen","NidoranM","Nidorino","Nidoking","Clefairy","Clefable","Vulpix","Ninetales","Jigglypuff","Wigglytuff","Zubat","Golbat","Oddish","Gloom","Vileplume","Paras","Parasect","Venonat","Venomoth","Diglett","Dugtrio","Meowth","Persian","Psyduck","Golduck","Mankey","Primeape","Growlithe","Arcanine","Poliwag","Poliwhirl","Poliwrath","Abra","Kadabra","Alakazam","Machop","Machoke","Machamp","Bellsprout","Weepinbell","Victreebel","Tentacool","Tentacruel","Geodude","Graveler","Golem","Ponyta","Rapidash","Slowpoke","Slowbro","Magnemite","Magneton","Farfetchd","Doduo","Dodrio","Seel","Dewgong","Grimer","Muk","Shellder","Cloyster","Gastly","Haunter","Gengar","Onix","Drowzee","Hypno","Krabby","Kingler",};
		dex = sortDex(dex);
		return dex;
	}
	
	private static String[] sortDex(String pokeSort[]) 
	{
		
		int minimum = 0;
		String hold = ""; 
		
		for (int x = 0; x < pokeSort.length; x++)
		{
			minimum = x;
			for (int y = x+1; y < pokeSort.length - 1; y++)
			{
				if (pokeSort[y].compareToIgnoreCase(pokeSort[minimum]) < 0)
					minimum = y;
			}
			hold = pokeSort[minimum];
			pokeSort[minimum] = pokeSort[x];
			pokeSort[x] = hold;
		}
		return pokeSort;
	}

	private static String binarySearch(String[] pokeDex, String pokemon) {
		botCut = 0;
		topCut = pokeDex.length - 1;
		
		if (botCut >= topCut)
			
			return "INVALID: STACK_OVERFLOW";
		
		while (topCut >= botCut)
		{
			
			middle = (botCut + topCut) / 2;
			
			if (pokeDex[middle].compareTo(pokemon) == 0)
			{
				
				return pokemon + "'s sorted dex number is " + (middle + 1);
				
			}
			
			else if (pokeDex[middle].compareTo(pokemon) > 0)
			{
				
				topCut = middle - 1;
				
			}
			
			else if (pokeDex[middle].compareTo(pokemon) < 0)
			{
				
				botCut = middle + 1;
				
			}
			
		}
		
		return pokemon + "'s sorted dex number is " + (middle + 1);
		
	}
	
}
