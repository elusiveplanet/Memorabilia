
public class SelectionSort {

	public static void main(String[] args) {
		String pokeSort[] = {"Bulbasaur","Ivysaur","Venusaur","Charmander","Charmeleon","Charizard","Squirtle","Wartortle","Blastoise","Caterpie","Metapod","Butterfree","Weedle","Kakuna","Beedrill","Pidgey","Pidgeotto","Pidgeot","Rattata","Raticate","Spearow","Fearow","Ekans","Arbok","Pikachu","Raichu","Sandshrew","Sandslash","NidoranF","Nidorina","Nidoqueen","NidoranM","Nidorino","Nidoking","Clefairy","Clefable","Vulpix","Ninetales","Jigglypuff","Wigglytuff","Zubat","Golbat","Oddish","Gloom","Vileplume","Paras","Parasect","Venonat","Venomoth","Diglett","Dugtrio","Meowth","Persian","Psyduck","Golduck","Mankey","Primeape","Growlithe","Arcanine","Poliwag","Poliwhirl","Poliwrath","Abra","Kadabra","Alakazam","Machop","Machoke","Machamp","Bellsprout","Weepinbell","Victreebel","Tentacool","Tentacruel","Geodude","Graveler","Golem","Ponyta","Rapidash","Slowpoke","Slowbro","Magnemite","Magneton","Farfetchd","Doduo","Dodrio","Seel","Dewgong","Grimer","Muk","Shellder","Cloyster","Gastly","Haunter","Gengar","Onix","Drowzee","Hypno","Krabby","Kingler"};
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
		for (int x = 0; x < (pokeSort.length - 1); x++)
        {
            System.out.println(pokeSort[x]);
        }
	}

}
