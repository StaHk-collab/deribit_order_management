# Deribit Order Execution and Management System

## Overview

This project is a C++ application that interacts with the Deribit API to manage cryptocurrency trading operations, including placing orders, canceling orders, modifying orders, retrieving the order book, and viewing current positions. The application is designed for use on the Deribit testnet.

## Features

- **Place Orders**: Submit buy or sell orders for a specified cryptocurrency.
- **Cancel Orders**: Cancel existing orders by providing their IDs.
- **Modify Orders**: Change the parameters of existing orders.
- **Get Order Book**: Retrieve the current order book for a specified cryptocurrency.
- **View Current Positions**: Display current trading positions.

## Requirements

- C++11 or later
- [cURL](https://curl.se/) library
- [nlohmann/json](https://github.com/nlohmann/json) for JSON parsing (install via vcpkg or manually)

## Installation

1. **Clone the Repository**:
   
   ```bash
   git clone https://github.com/yourusername/deribit_order_management.git
   cd deribit_order_management
   ```
2. **Install Dependencies**:
   
   ```bash
   vcpkg install curl
   vcpkg install nlohmann-json
   ```
3. **Build the Application**:
   
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build . --config Release
   ```

## Configuration

Before running the application, you need to set your API credentials. Edit the ```config.h ``` file:

```bash
#pragma once

const std::string API_KEY = "your_api_key_here"; // Replace with your API key
const std::string SECRET_KEY = "your_secret_key_here"; // Replace with your secret key
```

## Running the Application

After building the application, you can run the executable:

```bash
cd Release
./deribit_order_management.exe
```

## Testing with Postman

To test the API endpoints using Postman, you can import the exported Postman collection JSON file provided in this repository.

### Available Endpoints

1. **Authenticate**
   
   - Method: POST
   - Endpoint: ``` https://test.deribit.com/api/v2/public/auth ```
   - Body: <br>
   
         {
            "grant_type": "client_credentials",
            "scope": "session:apiconsole-<your_session_id>",
            "client_id": "your_api_key",
            "client_secret": "your_secret_key"
          }

2. **Place Order**
   
   - Method: POST
   - Endpoint: ``` https://test.deribit.com/api/v2/private/place_order ```
   - Body: <br>
   
         {
            "jsonrpc": "2.0",
            "method": "private/place_order",
            "params": {
              "instrument_name": "BTC-PERPETUAL",
              "amount": 1,
              "price": 30000,
              "type": "limit",
              "side": "buy"
            },
            "id": 1
         }

3. **Cancel Order**

   - Method: POST
   - Endpoint: ``` https://test.deribit.com/api/v2/private/cancel_order ```
   - Body: <br>
   
         {
            "jsonrpc": "2.0",
            "method": "private/cancel_order",
            "params": {
              "order_id": "your_order_id"
            },
            "id": 1
         }

4. **Modify Order**

   - Method: POST
   - Endpoint: ``` https://test.deribit.com/api/v2/private/modify_order ```
   - Body: <br>
   
         {
            "jsonrpc": "2.0",
            "method": "private/modify_order",
            "params": {
              "order_id": "your_order_id",
              "amount": 2,
              "price": 31000
            },
            "id": 1
         }

5. **Get Order Book**

   - Method: POST
   - Endpoint: ``` https://test.deribit.com/api/v2/public/get_order_book ```
   - Body: <br>
   
          {
            "jsonrpc": "2.0",
            "method": "public/get_order_book",
            "params": {
              "instrument_name": "BTC-PERPETUAL"
            },
            "id": 4
          }
  
6. **Get Current Positions**

   - Method: POST
   - Endpoint: ``` https://test.deribit.com/api/v2/private/get_positions ```
   - Body: <br>

         {
          "jsonrpc": "2.0",
          "method": "private/get_positions",
          "params": {
            "currency": "BTC",
            "kind": "future"
          },
          "id": 5
         }

