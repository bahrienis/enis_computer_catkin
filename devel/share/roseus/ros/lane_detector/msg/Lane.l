;; Auto-generated. Do not edit!


(when (boundp 'lane_detector::Lane)
  (if (not (find-package "LANE_DETECTOR"))
    (make-package "LANE_DETECTOR"))
  (shadow 'Lane (find-package "LANE_DETECTOR")))
(unless (find-package "LANE_DETECTOR::LANE")
  (make-package "LANE_DETECTOR::LANE"))

(in-package "ROS")
;;//! \htmlinclude Lane.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass lane_detector::Lane
  :super ros::object
  :slots (_header _left_line _right_line _guide_line ))

(defmethod lane_detector::Lane
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:left_line __left_line) (let (r) (dotimes (i 0) (push (instance geometry_msgs::Point32 :init) r)) r))
    ((:right_line __right_line) (let (r) (dotimes (i 0) (push (instance geometry_msgs::Point32 :init) r)) r))
    ((:guide_line __guide_line) (let (r) (dotimes (i 0) (push (instance geometry_msgs::Point32 :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _left_line __left_line)
   (setq _right_line __right_line)
   (setq _guide_line __guide_line)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:left_line
   (&rest __left_line)
   (if (keywordp (car __left_line))
       (send* _left_line __left_line)
     (progn
       (if __left_line (setq _left_line (car __left_line)))
       _left_line)))
  (:right_line
   (&rest __right_line)
   (if (keywordp (car __right_line))
       (send* _right_line __right_line)
     (progn
       (if __right_line (setq _right_line (car __right_line)))
       _right_line)))
  (:guide_line
   (&rest __guide_line)
   (if (keywordp (car __guide_line))
       (send* _guide_line __guide_line)
     (progn
       (if __guide_line (setq _guide_line (car __guide_line)))
       _guide_line)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; geometry_msgs/Point32[] _left_line
    (apply #'+ (send-all _left_line :serialization-length)) 4
    ;; geometry_msgs/Point32[] _right_line
    (apply #'+ (send-all _right_line :serialization-length)) 4
    ;; geometry_msgs/Point32[] _guide_line
    (apply #'+ (send-all _guide_line :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; geometry_msgs/Point32[] _left_line
     (write-long (length _left_line) s)
     (dolist (elem _left_line)
       (send elem :serialize s)
       )
     ;; geometry_msgs/Point32[] _right_line
     (write-long (length _right_line) s)
     (dolist (elem _right_line)
       (send elem :serialize s)
       )
     ;; geometry_msgs/Point32[] _guide_line
     (write-long (length _guide_line) s)
     (dolist (elem _guide_line)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; geometry_msgs/Point32[] _left_line
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _left_line (let (r) (dotimes (i n) (push (instance geometry_msgs::Point32 :init) r)) r))
     (dolist (elem- _left_line)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; geometry_msgs/Point32[] _right_line
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _right_line (let (r) (dotimes (i n) (push (instance geometry_msgs::Point32 :init) r)) r))
     (dolist (elem- _right_line)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; geometry_msgs/Point32[] _guide_line
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _guide_line (let (r) (dotimes (i n) (push (instance geometry_msgs::Point32 :init) r)) r))
     (dolist (elem- _guide_line)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get lane_detector::Lane :md5sum-) "c90a7e3d5672c12e51f2e3f5f1598108")
(setf (get lane_detector::Lane :datatype-) "lane_detector/Lane")
(setf (get lane_detector::Lane :definition-)
      "Header header
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
")



(provide :lane_detector/Lane "c90a7e3d5672c12e51f2e3f5f1598108")


