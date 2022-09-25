class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> map = new HashMap<>();
        
        List<List<String>> res = new ArrayList<>();

        for(String path : paths){
            String[] s = path.split(" ");
            // root is s[0]
            String root = s[0];
            
            for(int i = 1; i < s.length; i++){
                String[] file = processFile(s[i]);
                String fileName = file[0];
                String content = file[1];
                
                map.computeIfAbsent(
                    content, k -> new ArrayList<>())                                  .add(root + "/" + fileName);
            }
        }
        
        for(var values : map.values()){
            if(values.size() > 1)
                res.add(values);
        }
        
        return res;
    }
    
    String[] processFile(String file){
        StringBuilder fileName = new StringBuilder();
        
        int i = 0;
        while(file.charAt(i) != '(') {
            fileName.append(file.charAt(i++));
        }
        
        String content = file.substring(i+1, file.length() - 1);
        
        return new String[]{fileName.toString(), content};
        // return res;
    }
}