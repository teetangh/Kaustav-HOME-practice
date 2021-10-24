from gensim.models import Word2Vec
import os
import numpy as np
import multiprocessing

documents = ['Well done!',
		'Good work',
		'Great effort',
		'nice work',
		'Excellent!',
		'Weak',
		'Poor effort!',
		'not good',
		'poor work',
		'Could have done better.']


w2v_model  = None
model_path = f'models/word2vec.model'
EMBEDDING_SIZE = 5
MAX_LENGTH = 5
NUM_CORES = multiprocessing.cpu_count()

# Load the Word2Vec model if it exists
w2v_model = Word2Vec(
    documents,
    vector_size=EMBEDDING_SIZE,
    min_count=1,
    window=5,
    workers=NUM_CORES,
    seed=1337
)


# Encode the documents using the new embedding
encoded_docs = [[w2v_model.wv[word] for word in post] for post in documents]

for i in encoded_docs:
    print(len(i),end="\n\n")


padded_posts = []

for post in encoded_docs:
    # Pad short posts with alternating min/max
    if len(post) < MAX_LENGTH:
        
        # Method 1
        pointwise_min = np.minimum.reduce(post)
        pointwise_max = np.maximum.reduce(post)
        padding = [pointwise_max, pointwise_min]
        
        # Method 2
        pointwise_avg = np.mean(post)
        padding = [pointwise_avg]
        
        print(post)
        print(padding)
        post += padding * int(np.ceil((MAX_LENGTH - len(post) / 2.0)))
        
    # Shorten long posts or those odd number length posts we padded to 51
    if len(post) > MAX_LENGTH:
        post = post[:MAX_LENGTH]
    
    # Add the post to our new list of padded posts
    padded_posts.append(post)

for i in padded_posts:
    print(i,end="\n\n")
