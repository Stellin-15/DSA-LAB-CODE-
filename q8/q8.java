import java.util.*;

class node {
    String hostname;
    String ip_address;
    node next;

    node(String hostname, String ip_address) {
        this.hostname = hostname;
        this.ip_address = ip_address;
    }

    String getHostname() {
        return hostname;
    }

    String getIpAddress() {
        return ip_address;
    }
}

class spearateChaining {
    node[] array;
    int capacity;
    long a;

    spearateChaining(int capacity, long a) {
        this.capacity = capacity;
        this.a = a;
        array = new node[capacity];
    }

    long hashing(String host) {
        long sum = 0;
        for (int i = 0; i < host.length(); i++) {
            sum += host.codePointAt(i) + Math.pow(a, i);
        }
        return sum;

    }

    int hashcompress(long sum) {
        return (int) (sum % 17);
    }

    void insert(String hostname, String ip_address) {
        node newNode = new node(hostname, ip_address);
        long hash = hashing(hostname);
        int index = hashcompress(hash);

        node currentNode = array[index];

        if (currentNode == null) {
            array[index] = newNode;
            return;
        }
        while (currentNode != null && currentNode.next != null) {
            currentNode = currentNode.next;
        }
        currentNode.next = newNode;
    }

    public void display() {
        for (int i = 0; i < array.length; i++) {
            System.out.printf("Index [%d]:\n", i);
            node cursor = array[i];
            while (cursor != null) {
                System.out.printf("  %s | %s\n", cursor.getHostname(), cursor.getIpAddress());
                cursor = cursor.next;
            }
            System.out.println();
        }

    }

    public void find(String hostname) {
        long hashCode = hashing(hostname);
        int index = hashcompress(hashCode);

        node currentNode = array[index];
        while (currentNode != null && !currentNode.getHostname().equals(hostname)) {
            currentNode = currentNode.next;
        }
        if (currentNode == null) {
            System.out.println("Host Name not Found!");
            return;
        }
        System.out.printf(" The hostname %s is present in the hash table\n The IP Address is %s\n",
                currentNode.getHostname(), currentNode.getIpAddress());
    }

}

class q8 {

    public static void main(String args[]) {
        spearateChaining hashTable = new spearateChaining(17,33);

        Scanner sc = new Scanner(System.in);
        int option = 0;
        hashTable.insert("bbc.co.uk",            "212.58.241.131");
        hashTable.insert("aljazeera.com",        "198.78.201.252");
        hashTable.insert("youtube.com",          "74.125.65.91");
        hashTable.insert("yahoo.com",            "98.137.149.56");
        hashTable.insert("bing.com",             "65.55.175.254");
        hashTable.insert("github.com",           "207.97.227.239");
        hashTable.insert("thepiratebay.org",     "194.71.107.15");
        hashTable.insert("mininova.com",         "80.94.76.5");
        hashTable.insert("facebook.com",         "31.13.77.36");
        hashTable.insert("twitter.com",          "199.59.149.230");
        hashTable.insert("tumblr.com",           "174.121.194.34");
        hashTable.insert("tumblr.com",           "174.121.194.34");
        hashTable.insert("tumblr.com",           "174.121.194.34");
        hashTable.insert("livejournal.com",      "209.200.154.225");
        hashTable.insert("dreamwidth.org",       "69.174.244.50");
        hashTable.insert("amazon.com",           "72.21.211.176");
        hashTable.insert("mediafire.com",        "205.196.120.13");
        hashTable.insert("megaupload.com",       "174.140.154.20");
        hashTable.insert("fileshare.com",        "208.87.33.151");
        while (true) {
            System.out.println(
                    "\nPlease Choose and Option:\n\t1. Insert hostname with IP\n\t2. Find hostname\n\t3. Display\n\t4. Exit");
            System.out.print("  => ");
            try {
                option = Integer.parseInt(sc.nextLine());
            } catch (Exception e) {
                System.out.println("\nInvalid Input!\n");
                break;
            }

            // gate condition
            if (option > 4 || option < 1) {
                System.out.println("\nPlease enter a valid option!\n");

            }

            // 1. Insert
            else if (option == 1) {
                System.out.println("\nPlease enter a Hostname to Insert:");
                System.out.print("  => ");
                String hostname = sc.nextLine();
                System.out.println("Please enter a IP Address to Insert:");
                System.out.print("  => ");
                String ipAddress = sc.nextLine();
                hashTable.insert(hostname, ipAddress);
            }

            // 2. Find
            else if (option == 2) {
                System.out.println("\nPlease enter a Hostname to Search:");
                System.out.print("  => ");
                String hostname = sc.nextLine();
                hashTable.find(hostname);
            }

            // 3. Display
            else if (option == 3) {
                System.out.println("\nDisplaying Entire Hash Table:\n");
                hashTable.display();
            }

            // 4. Exit
            else if (option == 4) {
                System.out.println("\nBye!\n");
                break;
            }
        }
    }
}