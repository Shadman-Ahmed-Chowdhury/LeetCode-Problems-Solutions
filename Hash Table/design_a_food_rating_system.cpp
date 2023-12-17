// Problem link: https://leetcode.com/problems/design-a-food-rating-system/

// My solution:
class FoodRatings {
    unordered_map <string, int> foodRating;
    unordered_map <string, string> foodCuisine;
    unordered_map <string, set <pair <int, string>>> cuisineRatingFood;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        for (int i = 0; i < foods.size(); i++) {
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            cuisineRatingFood[cuisines[i]].insert({ -ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        // Find cuisine name from foodCuisine.
        string cuisineName = foodCuisine[food];

        // Erase element from cuisineRatingFood by searching using cuisine.
        auto oldCuisineItr = cuisineRatingFood[cuisineName].find({
            -foodRating[food], food
        });

        cuisineRatingFood[cuisineName].erase(oldCuisineItr);
        // Update rating in foodRating.
        foodRating[food] = newRating;
        // Insert new element in cuisineRatingFood with newRating.
        cuisineRatingFood[cuisineName].insert({
            -newRating, food
        });
    }
    
    string highestRated(string cuisine) {
        auto highestRatedCuisine = *cuisineRatingFood[cuisine].begin();
        // Return the food name of the cuisine.
        return highestRatedCuisine.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */