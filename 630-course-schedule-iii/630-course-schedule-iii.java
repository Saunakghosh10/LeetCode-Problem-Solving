

//Short version of the code 
public class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (a,b)-> a[1]==b[1] ? a[0]-b[0] : a[1]-b[1]);
        PriorityQueue<Integer> pq=new PriorityQueue<>((a,b)->b-a);
        int time=0;
        for (int[] course : courses) 
        {
			//Add current course to a priority queue
            time+=course[0]; 
            pq.offer(course[0]);
			//If time exceeds, drop the previous course which costs the most time.
            if (time>course[1]) time-=pq.poll(); 
        }        
        return pq.size();
    }
}