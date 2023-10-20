# SuperDuper

Video Demo Link: https://youtu.be/GRXRba9Xr80

Aayesha Islam, Brenda Nakasone, Lauren Nunag
COP3530
Project 3b Report
Administrative:
Our team name is the “Makeup Gurus”; we thought this name would be fitting because Makeup Gurus are usually Youtubers who review makeup products or upload tutorials on how to do makeup. Our team members were Aayesha Islam, Brenda Nakasone, and Lauren Nunag. Our project name is “Super Duper: The Best Way to Find Your Dupes.” Our GitHub link can be found here: https://github.com/lauren-nunag/SuperDuper.git and our Youtube link can be found here https://youtu.be/GRXRba9Xr80. 


Extended and Refined Proposal: 
We decided that we were gonna tackle the problem of make-up users around the world struggling to find affordable makeup products. Usually, affordable make-up products aren’t marketed as well as the high-end products. In addition, cheaper make-up products also tend to lack the same quality as more expensive products. A dupe is an affordable product that mirrors a more expensive one in quality, formula, and/or appearance. In other words, a dupe is a less expensive alternative to a pricy, high-end brand. Usually, trustable dupes can be found through articles and Youtube videos that showcase the Dupes. However, there is no centralized website or area where one can find or search all the dupes for a certain makeup product. 
Our motivation was exactly this: we want to reduce the struggle of having to look through millions of Youtube videos and review articles in order to find good dupes for high-end makeup products and centralize the dupe-searching.
 One of the features we implemented was an easy way to look up dupes that resembles a search-engine. An example is that the user will be able to input the type of make-up product that they are looking for and their maximum price that they are willing to pay for it. This type of make-up product is then searched in our database that contains over 100,000 makeup products and all of the make-up products that are under the price range are printed out. The information that is given is its product id, brand, category of the makeup, price, and rating. From then on, the user can decide which makeup product they would like to purchase instead of the high-end makeup product that they were looking for. 

Our data was an accumulation of sephora’s sold products and ulta’s inventory of products. Each make-up product has a corresponding product id, make-up brand, category of make-up, price, and review rating. These were stored as an integer, string, string, float, and float respectively. 
We decided to use the C++ language because all of our team members were familiar with the language. We also imported the climits and chrono library to facilitate the use of floats and timings respectively. 
The algorithms we decided to implement for the Minimum Heap were Heapify, Insert, and Extract. The algorithms we decided to implement for our Pairing Heap were Insert and Extract. 
We created a Makeup object that held the product’s information and pointers to the left and right siblings that corresponded to the heap. 
For the distribution of responsibilities, Aayesha was the creator of the Minimum Heap and also implemented the chrono timer into the project. Lauren researched and created the Pairing Heap. Brenda created the data set, debugged the Pairing Heap to help Lauren, and wrote this report. 
Analysis: 
After further revision, we decided not to implement the BRIDGES visualization because of our time constraints. We also decided to change our strategy to comparing two data structures rather than algorithms which was our former plan. This was because we realized that the algorithms that we wanted to compare required a more complex data structure that did not align with our goals for this project. We also realized that the data structures that we listed in the project plan were not easily comparable to each other. Despite all of the late realizations, we knew that we at least wanted to use a Minimum Heap to store our data set. Based on this information, we decided to do a pairing heap to compare the times that each heap takes to insert and delete a node into the Heap. 
	Here is a following list of the functions that we used, their time complexities and an explanation of their time complexities: 
MinHeap::InsertKey(MinMakeup k) = O(logn)
This worst time complexity is O(logn) because the insert function calls the MinHeapify function which has an O(logn) worst time complexity because it traverses one side of the heap.
MinHeap::MinHeapify(int i) = O(logn)
This function also only traverses one side of the heap (either the left or right side), therefore its worst time complexity is O(logn). 
MinHeap::extractMin() = O(logn)
This worst time complexity is O(logn) because although its main purpose is to access the minimum value in the heap, it also deletes the minimum value which leads to heapifying the heap. 
PairingHeap::Insert(Makeup* newMakeup) = O(1) 
The worst time complexity for Insert is O(1) because it simply adds the node to the heap without reorganizing any of the other nodes. 
PairingHeap::GetMin() = O(1)
This worst time complexity is O(1) because it simply accesses the root node and does not shift the heap in any way. 
The space complexity for both the min heap and the pairing heap is O(1).


Comparing our results, the insert function in the pairing heap takes O(1) worst time complexity while the insert function for the min heap takes O(logn). This means that the pairing heap is actually more efficient in terms of time complexity. For the extract minimum function for the minimum heap, it takes O(logn) while for the pairing heap it only takes O(1).


Reflection: 
For our overall experience as a group, we think it was good. There definitely could have been some improvements. However, our communication was good and we met several times to work on the project together. We started early and got a head start on our ideas. We lacked a little bit in cementing our ideas early on. This was because we had a lot of ideas on what to use for our data structures and algorithms, but had a hard time deciding which data structures and algorithms would work best with what we wanted to achieve. We believe this is where we fell back the most. 
One of the major challenges that we faced was understanding the pairing heap and implementing it. Since it was a topic that was not covered in class we had to do a lot of research ourselves on how it works. Another challenge that we faced was that Brenda was unable to work during the Thanksgiving break because of lack of internet. In addition, Aayesha fell sick during the execution of this project which prevented us from meeting in person. Both of these circumstances set us back a little. 
If we were to go back and add changes to workflow we believe we should have spent more time researching the data structures and algorithms towards the beginning of the project. We think that this was the biggest setback of the project. 
What we learned: 
Aayesha: My main benefit from this project was learning how to use and utilize github. This was a good opportunity to think about the practical implementation of a data structure I learned previously, which is the Binary Minheap, which allowed me to understand it on a deeper level and consider its applications. I also learned a new data structure which was the Pairing heap, and it was fascinating to understand the similarities and differences between the two structures and their performance. I also learned how to work with large data sets and how to calculate the runtime of any function within a program. Working with a group was also a good experience and helped me understand how to communicate my thoughts more efficiently. 
Brenda: Throughout this project I learned a lot about the Pairing Heap data structure. I learned that the way it stores its nodes is through most recently added unless the node’s value is less than the previous root’s value. I also learned how to set decimal places in excel and how to create randomized data. In terms of working with partners, I learned that being proactive and starting early is important to having a successful project. In addition, meeting often and frequently is good for updating each other on progress and deadlines need to be set. 
Lauren: Through this project, I learned about a new data structure that we did not discuss in class. This new data structure was a pairing heap and has properties of a left child and a sibling. I also learned about a new library that allowed us to time our program. I learned how to perform research outside of the given resources from the class, as I wanted to find more examples and demonstrations of the pairing heap. I learned more about how to use GitHub, however I still need to learn the more complex features. Additionally, I learned how to work effectively with a group instead of individually completing a project. I learned how to communicate, designate roles, collaborate, and ask each other questions when confusion arises. I feel that 




References: 
https://people.ksp.sk/~kuko/gnarley-trees/Pairing.html
https://brilliant.org/wiki/pairing-heap/
