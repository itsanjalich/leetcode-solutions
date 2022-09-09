class Solution {
    public int numberOfWeakCharacters(int[][] properties) {
        int len = properties.length;
        int count = 0;
        Arrays.sort(properties, (a, b) -> (b[0] == a[0]) ? (a[1] - b[1]) : (b[0] - a[0]));
        int max = 0;
        for (int i = 0; i < len; i++) {
            if (properties[i][1] < max) {
                count++;
            }
            max = Math.max(max, properties[i][1]);
        }
        return count;
    }
}