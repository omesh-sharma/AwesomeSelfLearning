from sklearn.feature_extraction.text import CountVectorizer


# Sample corpus
corpus = [
    "I love to eat pizza",
    "Pizza is my favorite food",
    "I enjoy eating pizza with friends",
    "I don't like vegetables",
    "I prefer pizza over salad"
]

# Initialize the CountVectorizer
vectorizer = CountVectorizer()

# Fit and transform the corpus into a feature matrix
features = vectorizer.fit_transform(corpus)

# Get the feature names
feature_names = vectorizer.get_feature_names_out()

# Print the feature matrix
print("Feature Matrix:")
print(features.toarray())
print()

# Print the feature names
print("Feature Names:")
print(feature_names)