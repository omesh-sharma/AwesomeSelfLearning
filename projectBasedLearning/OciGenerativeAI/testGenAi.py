import requests
import json

# Define your API endpoint and authentication token
api_endpoint = 'https://api.oracle.com/your-ai-service-endpoint'
api_key = 'your-api-key'

# Prepare request headers
headers = {
    'Authorization': f'Bearer {api_key}',
    'Content-Type': 'application/json'
}

# Example payloads for different features
payloads = {
    'text_generation': {
        'prompt': 'Once upon a time in a land far, far away',
        'parameters': {
            'temperature': 0.7,
            'max_tokens': 100
        }
    },
    'text_completion': {
        'prompt': 'The quick brown fox jumps over the',
        'parameters': {
            'temperature': 0.5,
            'max_tokens': 50
        }
    },
    'text_translation': {
        'text': 'Hello, how are you?',
        'parameters': {
            'source_language': 'en',
            'target_language': 'es'
        }
    }
}

def test_feature(feature_name, payload):
    print(f"Testing {feature_name}...")
    response = requests.post(api_endpoint, headers=headers, json=payload)
    
    if response.status_code == 200:
        data = response.json()
        print(f"Response for {feature_name}:")
        print(json.dumps(data, indent=2))
    else:
        print(f"Error testing {feature_name}:")
        print(f"Status Code: {response.status_code}")
        print(f"Response: {response.text}")

# Test each feature
for feature, payload in payloads.items():
    test_feature(feature, payload)
    print("\n" + "-"*50 + "\n")
