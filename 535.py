class Codec:
    dict = {"" : "n/a"}
    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        key = ""
        
        while key in self.dict.keys():
            key = ''.join(random.choice(string.ascii_uppercase + string.ascii_lowercase + string.digits) for _ in range(6))
        
        self.dict[key] = longUrl
        return key
            

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.dict[shortUrl]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
