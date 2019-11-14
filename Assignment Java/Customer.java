package Shop;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Customer {
	private String name;
	private double budget;
	private ArrayList<ProductStock> shoppingList;

	public Customer(String fileName) {
		// TODO
		shoppingList = new ArrayList<>();
		List<String> lines = Collections.emptyList();
		try {
			lines = Files.readAllLines(Paths.get(fileName), StandardCharsets.UTF_8);
			String[] firstline = lines.get(0).split(",");
			name = firstline[0];
			budget = Double.parseDouble(firstline[1]);
			// i am removing at index 0 as it is the only one treated differently
			lines.remove(0);
			for (String line : lines) {
				String[] arr = line.split(",");
				String name = arr[0];
				int quantity = Integer.parseInt(arr[1].trim());
				Product p = new Product(name, 0);
				ProductStock s = new ProductStock(p, quantity);
				shoppingList.add(s);
				//System.out.println(p);
				//System.out.println(s);
			}
			
		}

		catch (IOException e) {

			// do something
			e.printStackTrace();
		}
	}

	public String getName() {
		return name;
	}

	public double getBudget() {
		return budget;
	}

	public ArrayList<ProductStock> getShoppingList() {
		return shoppingList;
	}

	@Override
	public String toString() {
		String ret = "Customer [name=" + name + ", budget=" + budget + "\n" + "ShoppingList=\n";
		for (ProductStock productStock : shoppingList) {
			ret += productStock.getProduct().getName() + " Quantity: " + productStock.getQuantity() + "\n";
		}
		return ret  + "]";
	}
	
	public static void main(String[] args) {
		Customer Thor = new Customer("src/Shop/mppcustomer1.csv");
		System.out.println(Thor);
	}

}
