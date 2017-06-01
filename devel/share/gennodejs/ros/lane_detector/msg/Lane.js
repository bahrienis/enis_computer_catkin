// Auto-generated. Do not edit!

// (in-package lane_detector.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Lane {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.left_line = null;
      this.right_line = null;
      this.guide_line = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('left_line')) {
        this.left_line = initObj.left_line
      }
      else {
        this.left_line = [];
      }
      if (initObj.hasOwnProperty('right_line')) {
        this.right_line = initObj.right_line
      }
      else {
        this.right_line = [];
      }
      if (initObj.hasOwnProperty('guide_line')) {
        this.guide_line = initObj.guide_line
      }
      else {
        this.guide_line = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Lane
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [left_line]
    // Serialize the length for message field [left_line]
    bufferOffset = _serializer.uint32(obj.left_line.length, buffer, bufferOffset);
    obj.left_line.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point32.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [right_line]
    // Serialize the length for message field [right_line]
    bufferOffset = _serializer.uint32(obj.right_line.length, buffer, bufferOffset);
    obj.right_line.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point32.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [guide_line]
    // Serialize the length for message field [guide_line]
    bufferOffset = _serializer.uint32(obj.guide_line.length, buffer, bufferOffset);
    obj.guide_line.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point32.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Lane
    let len;
    let data = new Lane(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [left_line]
    // Deserialize array length for message field [left_line]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.left_line = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.left_line[i] = geometry_msgs.msg.Point32.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [right_line]
    // Deserialize array length for message field [right_line]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.right_line = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.right_line[i] = geometry_msgs.msg.Point32.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [guide_line]
    // Deserialize array length for message field [guide_line]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.guide_line = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.guide_line[i] = geometry_msgs.msg.Point32.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += 12 * object.left_line.length;
    length += 12 * object.right_line.length;
    length += 12 * object.guide_line.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'lane_detector/Lane';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c90a7e3d5672c12e51f2e3f5f1598108';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    geometry_msgs/Point32[] left_line
    geometry_msgs/Point32[] right_line
    geometry_msgs/Point32[] guide_line
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    ================================================================================
    MSG: geometry_msgs/Point32
    # This contains the position of a point in free space(with 32 bits of precision).
    # It is recommeded to use Point wherever possible instead of Point32.  
    # 
    # This recommendation is to promote interoperability.  
    #
    # This message is designed to take up less space when sending
    # lots of points at once, as in the case of a PointCloud.  
    
    float32 x
    float32 y
    float32 z
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Lane(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.left_line !== undefined) {
      resolved.left_line = new Array(msg.left_line.length);
      for (let i = 0; i < resolved.left_line.length; ++i) {
        resolved.left_line[i] = geometry_msgs.msg.Point32.Resolve(msg.left_line[i]);
      }
    }
    else {
      resolved.left_line = []
    }

    if (msg.right_line !== undefined) {
      resolved.right_line = new Array(msg.right_line.length);
      for (let i = 0; i < resolved.right_line.length; ++i) {
        resolved.right_line[i] = geometry_msgs.msg.Point32.Resolve(msg.right_line[i]);
      }
    }
    else {
      resolved.right_line = []
    }

    if (msg.guide_line !== undefined) {
      resolved.guide_line = new Array(msg.guide_line.length);
      for (let i = 0; i < resolved.guide_line.length; ++i) {
        resolved.guide_line[i] = geometry_msgs.msg.Point32.Resolve(msg.guide_line[i]);
      }
    }
    else {
      resolved.guide_line = []
    }

    return resolved;
    }
};

module.exports = Lane;
