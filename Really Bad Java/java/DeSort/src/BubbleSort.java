
public class BubbleSort {

	public static void main(String[] args) {
		String pokeSort[] = {"Bulbasaur","Ivysaur","Venusaur","Charmander","Charmeleon","Charizard","Squirtle","Wartortle","Blastoise","Caterpie","Metapod","Butterfree","Weedle","Kakuna","Beedrill","Pidgey","Pidgeotto","Pidgeot","Rattata","Raticate","Spearow","Fearow","Ekans","Arbok","Pikachu","Raichu","Sandshrew","Sandslash","NidoranF","Nidorina","Nidoqueen","NidoranM","Nidorino","Nidoking","Clefairy","Clefable","Vulpix","Ninetales","Jigglypuff","Wigglytuff","Zubat","Golbat","Oddish","Gloom","Vileplume","Paras","Parasect","Venonat","Venomoth","Diglett","Dugtrio","Meowth","Persian","Psyduck","Golduck","Mankey","Primeape","Growlithe","Arcanine","Poliwag","Poliwhirl","Poliwrath","Abra","Kadabra","Alakazam","Machop","Machoke","Machamp","Bellsprout","Weepinbell","Victreebel","Tentacool","Tentacruel","Geodude","Graveler","Golem","Ponyta","Rapidash","Slowpoke","Slowbro","Magnemite","Magneton","Farfetchd","Doduo","Dodrio","Seel","Dewgong","Grimer","Muk","Shellder","Cloyster","Gastly","Haunter","Gengar","Onix","Drowzee","Hypno","Krabby","Kingler"};
		boolean sorted = false;
		String hold;

		        while (sorted == false)
		        {
		        	sorted = true;
		            for (int x = 0; x < pokeSort.length - 2; x++)
		                if (pokeSort[x].compareToIgnoreCase(pokeSort[x+1]) > 0)
		                {
		                    hold = pokeSort[x];
		                    pokeSort[x] = pokeSort[x+1];
		                    pokeSort[x+1] = hold;
		                    sorted = false;
		                }
		        }

		        for (int x = 0; x < (pokeSort.length - 1); x++)
		        {
		            System.out.println(pokeSort[x]);
		        }
	}

}
