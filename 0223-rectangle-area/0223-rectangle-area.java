class Solution {
    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int x1 = Math.max(ax1, bx1), x2 = Math.min(ax2, bx2);
        int y1 = Math.max(ay1, by1), y2 = Math.min(ay2, by2);
        
        return  area(ax1, ay1, ax2, ay2) + area(bx1, by1, bx2, by2) - area(x1, y1, x2, y2);
    }
    
    private int area(int x1, int y1, int x2, int y2){
        if(x2-x1 < 0 || y2-y1 < 0) return 0;
        return (x2-x1)*(y2-y1);
    }
}