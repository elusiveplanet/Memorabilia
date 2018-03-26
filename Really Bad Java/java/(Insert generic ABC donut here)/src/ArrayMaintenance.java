import java.util.ArrayList;

public class ArrayMaintenance {

	public static void main(String[] args) {
		String[] arr = new String[] {"banana", "bread", "carrot", "egg", "fish", "", "", "", "", "", "", "", ""};


		arr = insert("donut", arr); //banana bread carrot donut egg fish
		arr = insert("apple", arr); //apple banana bread carrot donut egg fish
		arr = insert("burger", arr); //apple banana bread burger carrot donut egg fish
		arr = insert("lasagna", arr); //apple banana bread burger carrot donut egg fish lasagna
		//System.out.println(toString(arr));
		arr = remove("egg", arr); //apple banana bread burger carrot donut fish lasagna
		//System.out.println(toString(arr));
		arr = remove("banana", arr); //apple bread burger carrot donut fish lasagna
		//System.out.println(toString(arr));
		arr = insert("meatball", arr); //apple bread burger carrot donut fish lasagna meatball
		arr = insert("pear", arr);  //apple bread burger carrot donut fish lasagna meatball pear
		//System.out.println(toString(arr));
		arr = remove("pear", arr); //apple bread burger carrot donut fish lasagna meatball
		System.out.println(toString(arr));
	}
	
	public static String[] insert(String s, String[] arr1){
		String hold = "";
		//System.out.println(arr1.length);
		for (int i = 0; i < arr1.length; i++){
			if (arr1[i].compareTo(s) > 0 || arr1[i].equals("")){
				hold = arr1[i];
				arr1[i] = s;
				s = hold;
			}
		}
		//System.out.println(arr1.length);
		return arr1;
	}

	public static String toString(String[] arr1){
		String s="";
		for (int i = 0; i < arr1.length; i++){
			s += arr1[i] + "  ";
		}
		return s;
	}
	
	public static String[] remove(String str, String[] arrg)
	{
		ArrayList<String> temp = new ArrayList<String>();
		for (int i = 0; i < arrg.length; i++)
		{if (!arrg[i].equals(str)) temp.add(arrg[i]);}
		
		for (int i = 0; i < temp.size(); i++)
		{ arrg[i] = temp.get(i); }
		
		return arrg;
	}
	
}

