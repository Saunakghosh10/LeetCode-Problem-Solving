
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size(); // Get the size of the input vector 'dist' (number of distances to travel)
        int minSpeed = 1, maxSpeed = 1e7 + 1; // Initialize the minimum and maximum possible speeds
        int answer = -1; // Initialize the variable to store the final answer

        while (minSpeed < maxSpeed) { // Binary search loop to find the minimum required speed
            int midSpeed = minSpeed + (maxSpeed - minSpeed) / 2; // Calculate the middle speed

            double totalHours = 0.0; // Initialize total travel time to 0

            // Calculate the total hours required to travel each distance at the current middle speed
            for (int i = 0; i < n - 1; ++i) {
                // Add the time taken to travel distance at index i using current midSpeed to totalHours
                totalHours += std::ceil(static_cast<double>(dist[i]) / midSpeed);
            }
            // Add the time taken to travel the last distance using current midSpeed to totalHours
            totalHours += static_cast<double>(dist[n - 1]) / midSpeed;

            if (totalHours > hour) {
                // If the total hours exceed the given hour, update minSpeed to consider higher speeds
                minSpeed = midSpeed + 1;
            } else {
                // If the total hours are within the given hour, update the answer to the current speed
                // and search for a potentially smaller speed in the lower half of the range.
                answer = midSpeed;
                maxSpeed = midSpeed;
            }
        }

        return answer; // Return the minimum speed required to reach the destination on time
    }
};